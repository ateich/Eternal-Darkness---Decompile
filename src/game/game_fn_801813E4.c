typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_801991E0(void*, void*, int);
extern void fn_80181530(void*, void*, u16);
extern int fn_80180430(void*, u8);
extern u8 fn_8018E26C(void*, void*);
extern void fn_80180518(void*, u8, int);
extern void fn_8018E230(void*, void*, int, u8, u8, int);
extern void fn_8018E24C(void*, u8, int);

int fn_801813E4(u8* object)
{
    u8* state = object + 0x8C;
    int i;
    int tick;
    u8* entry;
    u8 count;

    (*(u16*)(object + 0x0A))++;
    if (state[5] & 0x80) {
        fn_801991E0(object, state + 0x48, 0x10);
    } else {
        tick = *(u16*)(object + 0x0A);
        entry = *(u8**)(object + 0x4C);
        fn_80181530(object, state, tick);
        count = object[1];
        for (i = 0; i < count; entry += 0x38, i++) {
            if (((state[5] & 0x40) || i < state[0]) &&
                fn_80180430(object + 0x24, (u8)i)) {
                if (entry[0] && !fn_8018E26C(entry, entry + 0x2B)) {
                    fn_80180518(object + 0x24, (u8)i, 0);
                }
                if (tick == *(u16*)(entry + 8)) {
                    if (state[4] == 1) {
                        fn_8018E230(entry, entry + 0x2B, 1, object[2],
                                    object[4], 0);
                    } else {
                        fn_8018E24C(entry, object[4], 0);
                    }
                }
            }
        }
        if (tick >= *(u16*)(object + 0x0C) ||
            (*(u16*)(state + 0x40) & 2)) {
            *(u16*)(object + 0x22) = 8;
        }
    }
    return 0;
}
