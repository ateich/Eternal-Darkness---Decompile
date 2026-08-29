typedef signed short s16;
typedef unsigned char u8;
typedef unsigned int u32;

extern const double lbl_80650B58;

void fn_80186E10(s16* output, int count, int low, int high, int offset);
void fn_80186F70(s16* output, int count, float step, float base, int range);

void fn_80194F80(const s16* first, const s16* second, const float* scale,
                 u8* state)
{
    u8 count = state[0xB] - 4;

    if (*(u32*)(state + 0x7C) & 0x10000) {
        fn_80186E10((s16*)(state + 0x28), count, first[0], second[0],
                    state[0xC]);
    } else {
        fn_80186F70((s16*)(state + 0x28), count, scale[0], (float)first[0],
                    state[3]);
    }
    if (*(u32*)(state + 0x7C) & 0x20000) {
        fn_80186E10((s16*)(state + 0x42), count, first[1], second[1],
                    state[0xC]);
    } else {
        fn_80186F70((s16*)(state + 0x42), count, scale[1], (float)first[1],
                    state[3]);
    }
    if (*(u32*)(state + 0x7C) & 0x2000) {
        fn_80186E10((s16*)(state + 0x5C), count, first[2], second[2],
                    state[0xC]);
    } else {
        fn_80186F70((s16*)(state + 0x5C), count, scale[2], (float)first[2],
                    state[3]);
    }
}
