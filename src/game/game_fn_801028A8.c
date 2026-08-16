typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef struct DecodeTree {
    s32 count;
    s32 root;
    s16 left[512];
    s16 right[512];
} DecodeTree;

typedef struct BitReader {
    const u8* input;
    u8 pad04[8];
    u8 current;
    u8 mask;
} BitReader;

extern s32 lbl_8064CC68;
extern s32 lbl_8064CC6C;

static int read_bit(BitReader* reader)
{
    int bit;

    if (reader->mask == 0) {
        reader->current = *reader->input++;
        reader->mask = 0x80;
    }
    bit = reader->current & reader->mask;
    reader->mask >>= 1;
    return bit != 0;
}

int fn_801028A8(DecodeTree* tree, BitReader* reader)
{
    int value;
    int node;
    int stored;

    if (read_bit(reader)) {
        node = tree->count++;
        tree->left[node] = fn_801028A8(tree, reader);
        tree->right[node] = fn_801028A8(tree, reader);
        return (s16)node;
    }

    value = read_bit(reader) ? 0x80 : 0;
    value |= read_bit(reader) ? 0x40 : 0;
    value |= read_bit(reader) ? 0x20 : 0;
    value |= read_bit(reader) ? 0x10 : 0;
    value |= read_bit(reader) ? 8 : 0;
    value |= read_bit(reader) ? 4 : 0;
    value |= read_bit(reader) ? 2 : 0;
    value |= read_bit(reader) ? 1 : 0;

    stored = value;
    if (lbl_8064CC68 != 0 && (s16)value > 127) {
        stored -= 256;
    }
    stored = (s16)stored << lbl_8064CC6C;
    tree->left[(s16)value] = (s16)stored;
    return value;
}
