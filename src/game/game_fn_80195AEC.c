typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void fn_80187320(void*, u16*, s16*, int, int, int, int, s16, u8, int,
                 float);
void fn_801875FC(void*, u16*, s16*, int, int, int, s16*, void*, u8,
                 int);

/*
 * Updates the three independently encoded coordinate channels.  Retail has
 * additional split/interleaved paths for flags 0x100..0x20000; keeping the
 * recovered direct paths in C makes the remaining codegen debt explicit.
 */
void fn_80195AEC(u8* object)
{
    u32 flags = *(u32*)(object + 0x108);
    u8 count = object[0x97] - 4;
    int end = ((*(u16*)(object + 0x9c) & 7) + 1);
    u8 kind = object[0x8f];
    u8 mode = object[0x98];
    u8* owner = *(u8**)(object + 0x4c);
    s16* starts = (s16*)(object + 0x10);

    if (!(flags & 0x10000)) {
        if (flags & 0x20000) {
            fn_801875FC(owner + 0x38, (u16*)(object + 0x9c),
                        (s16*)(object + 0xb4), 0, 0, count, starts,
                        object + 0xa2, mode, end);
        } else {
            fn_80187320(owner + 0x38, (u16*)(object + 0x9c),
                        (s16*)(object + 0xb4), 0, 0, count, 0, starts[0],
                        kind, end, *(float*)(object + 0x10c));
        }
        if (flags & 0x20000) {
            fn_801875FC(owner + 0x38, (u16*)(object + 0x9e),
                        (s16*)(object + 0xce), 1, 0, count, starts,
                        object + 0xa2, mode, end);
        } else {
            fn_80187320(owner + 0x38, (u16*)(object + 0x9e),
                        (s16*)(object + 0xce), 1, 0, count, 0, starts[1],
                        kind, end, *(float*)(object + 0x110));
        }
        if (flags & 0x2000) {
            fn_801875FC(owner + 0x38, (u16*)(object + 0xa0),
                        (s16*)(object + 0xe8), 2, 0, count, starts,
                        object + 0xa2, mode, end);
        } else {
            fn_80187320(owner + 0x38, (u16*)(object + 0xa0),
                        (s16*)(object + 0xe8), 2, 0, count, 0, starts[2],
                        kind, end, *(float*)(object + 0x114));
        }
    }
}
