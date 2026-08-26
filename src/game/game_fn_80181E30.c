typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern int fn_80180430(void*, u8);
extern void fn_80180518(void*, u8, int);
extern int fn_80180454(void*);
extern u8 fn_8018E26C(void*, void*);
extern void fn_8018E230(void*, void*, int, u8, int, int);
extern void fn_80181808(void*, int, s16);

int fn_80181E30(u8* object)
{
    int i;
    u16 tick;
    u8* state;
    u8* entry;
    u8 count;

    i = 0;
    state = object + 0x8C;
    entry = *(u8**)(object + 0x4C);
    *(u16*)(object + 0xA) += 1;
    tick = *(u16*)(object + 0xA);
    count = object[1];

    for (; i < count; entry += 0x38, i++) {
        if (fn_80180430(object + 0x24, (u8)i)) {
            *(s16*)(entry + 0x14) += *(s16*)(entry + 0x1A);
            if (!fn_8018E26C(entry, entry + 0x2B)) {
                fn_80180518(object + 0x24, (u8)i, 0);
            }
            fn_80181808(state, i, 1);
        }
    }

    if (!(tick & *(u16*)(state + 0xA)) && state[0] < count - 1) {
        state[0]++;
        entry = *(u8**)(object + 0x4C) + state[0] * 0x38;
        fn_80180518(object + 0x24, state[0], 1);
        fn_8018E230(entry, entry + 0x2B, 1, object[2], object[4], 0);
    }

    if (fn_80180454(object + 0x24)) {
        *(u16*)(object + 0x22) = 8;
    }
    return 0;
}
