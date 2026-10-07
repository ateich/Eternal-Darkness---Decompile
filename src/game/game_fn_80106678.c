typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

typedef struct DecodeTree DecodeTree;

typedef struct BitReader {
    const u8* input;
    u8 pad04[8];
    u8 current;
    u8 mask;
    u8 pad0E[2];
    DecodeTree* tree;
} BitReader;

typedef struct SrcPlane {
    u8* blocks;
    u8 pad04[0x24];
    int size;
    u8 pad2C[0xC];
} SrcPlane;

typedef struct Decoder {
    u8 pad00[4];
    SrcPlane planes[3];
    u8 pad_ac[0x320C - 0xAC];
    BitReader mv_x;
    BitReader mv_y;
    u8 pad3234[0x3CCC - 0x3234];
    u8 range_x[2];
    u8 range_y[2];
} Decoder;

typedef struct Movie {
    Decoder* decoder;
    u16 width;
    u16 height;
} Movie;

typedef struct PlaneCursor {
    u8* blocks;
    u8* block_row;
    int row;
    int pos;
    int ref;
    int refs[2];
    u16 block_step;
    int row_step;
    int blocks_step;
    int block_row_step;
    u8 pad2C[8];
} PlaneCursor;

typedef struct FrameContext {
    u8 pad00[8];
    PlaneCursor planes[3];
} FrameContext;

s16 fn_80102C6C(BitReader* reader);
void fn_80104B30(Decoder* decoder, FrameContext* ctx, int dest, int arg2, int arg3);
void fn_801061E0(Movie* movie, FrameContext* ctx);
void fn_80106088(Decoder* decoder, FrameContext* ctx);
void fn_80105DE0(Decoder* decoder, FrameContext* ctx, int x, int y);
void fn_8010528C(Decoder* decoder, FrameContext* ctx, int x, int y);

static inline int ReadMotion(BitReader* reader, int bits)
{
    int value = fn_80102C6C(reader) << bits;
    int i;

    for (i = bits - 1; i >= 0; i--) {
        int bit;
        int set;

        if (reader->mask == 0) {
            reader->current = *reader->input++;
            reader->mask = 0x80;
        }
        set = 1;
        bit = reader->current & reader->mask;
        reader->mask >>= 1;
        if ((u8)bit == 0) {
            set = 0;
        }
        value += set << i;
    }
    return value;
}

void fn_80106678(Movie* movie, int dest, int arg2, int arg3)
{
    FrameContext ctx;
    Decoder* decoder = movie->decoder;
    int y;
    int x;
    int ref;
    int mv_x;
    int mv_y;

    fn_80104B30(decoder, &ctx, dest, arg2, arg3);
    fn_801061E0(movie, &ctx);

    ctx.planes[0].row = dest;
    ref = -1;
    ctx.planes[0].blocks = ctx.planes[0].block_row = decoder->planes[0].blocks;
    ctx.planes[1].row = dest + decoder->planes[0].size;
    ctx.planes[1].blocks = ctx.planes[1].block_row = decoder->planes[1].blocks;
    ctx.planes[2].row = ctx.planes[1].row + decoder->planes[1].size;
    ctx.planes[2].blocks = ctx.planes[2].block_row = decoder->planes[2].blocks;

    for (y = 0; y < movie->height; y += 8) {
        ctx.planes[0].pos = ctx.planes[0].row;
        ctx.planes[1].pos = ctx.planes[1].row;
        ctx.planes[2].pos = ctx.planes[2].row;

        for (x = 0; x < movie->width; x += 8) {
            u8 flags = ctx.planes[0].blocks[1];
            int type = (flags >> 5) & 3;

            if (type == 0) {
                fn_80106088(decoder, &ctx);
            } else {
                int range;

                if (type - 1 != ref) {
                    ref = type - 1;
                    if (ref == 0) {
                        ctx.planes[0].ref = ctx.planes[0].refs[0];
                        ctx.planes[1].ref = ctx.planes[1].refs[0];
                        ctx.planes[2].ref = ctx.planes[2].refs[0];
                    } else {
                        ctx.planes[0].ref = ctx.planes[0].refs[1];
                        ctx.planes[1].ref = ctx.planes[1].refs[1];
                        ctx.planes[2].ref = ctx.planes[2].refs[1];
                    }
                    mv_y = 0;
                    mv_x = 0;
                }

                range = 1 << (decoder->range_x[ref] + 5);
                mv_x += ReadMotion(&decoder->mv_x, decoder->range_x[ref]);
                if (mv_x >= range) {
                    mv_x -= range * 2;
                } else if (mv_x < -range) {
                    mv_x += range * 2;
                }

                range = 1 << (decoder->range_y[ref] + 5);
                mv_y += ReadMotion(&decoder->mv_y, decoder->range_y[ref]);
                if (mv_y >= range) {
                    mv_y -= range * 2;
                } else if (mv_y < -range) {
                    mv_y += range * 2;
                }

                if (!((flags >> 4) & 1)) {
                    fn_80105DE0(decoder, &ctx, x * 2 + mv_x, y * 2 + mv_y);
                } else {
                    fn_8010528C(decoder, &ctx, x * 2 + mv_x, y * 2 + mv_y);
                }
            }

            ctx.planes[0].pos += ctx.planes[0].block_step;
            ctx.planes[0].blocks += ctx.planes[0].blocks_step * 2;
            ctx.planes[1].pos += ctx.planes[1].block_step;
            ctx.planes[1].blocks += ctx.planes[1].blocks_step * 2;
            ctx.planes[2].pos += ctx.planes[2].block_step;
            ctx.planes[2].blocks += ctx.planes[2].blocks_step * 2;
        }

        ctx.planes[0].row += ctx.planes[0].row_step;
        ctx.planes[0].blocks = ctx.planes[0].block_row += ctx.planes[0].block_row_step * 2;
        ctx.planes[1].row += ctx.planes[1].row_step;
        ctx.planes[1].blocks = ctx.planes[1].block_row += ctx.planes[1].block_row_step * 2;
        ctx.planes[2].row += ctx.planes[2].row_step;
        ctx.planes[2].blocks = ctx.planes[2].block_row += ctx.planes[2].block_row_step * 2;
    }
}
