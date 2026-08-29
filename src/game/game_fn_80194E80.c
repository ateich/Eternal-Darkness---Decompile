typedef signed short s16;
typedef unsigned char u8;
typedef unsigned int u32;

void fn_80186C88(s16* output, int count, int base, int step, int range);
void fn_80186D74(s16* output, int count, int first, int second, int range);

void fn_80194E80(const s16* first, const s16* second, const s16* third,
                 u8* state)
{
    u8 count = state[0xB] - 4;

    if (*(u32*)(state + 0x7C) & 0x10000) {
        fn_80186D74((s16*)(state + 0x28), count, first[0], second[0],
                    state[0xC]);
    } else {
        fn_80186C88((s16*)(state + 0x28), count, third[0], first[0],
                    state[3]);
    }
    if (*(u32*)(state + 0x7C) & 0x20000) {
        fn_80186D74((s16*)(state + 0x42), count, first[1], second[1],
                    state[0xC]);
    } else {
        fn_80186C88((s16*)(state + 0x42), count, third[1], first[1],
                    state[3]);
    }
    if (*(u32*)(state + 0x7C) & 0x2000) {
        fn_80186D74((s16*)(state + 0x5C), count, first[2], second[2],
                    state[0xC]);
    } else {
        fn_80186C88((s16*)(state + 0x5C), count, third[2], first[2],
                    state[3]);
    }
}
