typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;

extern void* lbl_8064D18C;
extern u8 fn_8018E26C(void*, void*);
extern void fn_80180518(void*, u8, int);
extern int fn_80180430(void*, u8);
extern void fn_8017E1E4(void*, void*, u8, int);
extern void fn_8018E230(void*, void*, int, u8, u8, int);
extern int fn_80180454(void*);

int fn_8019DDBC(u8* object)
{
    s16* timer;
    int count;
    u8* state;
    u8* entry;
    int i;

    state = object + 0x8C;
    i = 0;
    timer = (s16*)state;
    entry = *(u8**)(object + 0x4C);
    count = object[1];

    while (i < count) {
        if (entry[0] == 1 && !fn_8018E26C(entry, entry + 0x2B) &&
            entry[0x2B] == 0 && entry[1] == 0) {
            fn_80180518(object + 0x24, (u8)i, 0);
        }
        if (fn_80180430(object + 0x24, (u8)i)) {
            fn_8017E1E4(entry + 0xA, entry + 0x10, state[0x73], ((s8*)state)[0x74]);
            if (entry[0] == 0) {
                fn_8018E230(entry, entry + 0x2B, 1, entry[0x2B], object[4], 0);
            }
        }
        timer[6]++;
        entry += 0x38;
        i++;
        timer++;
    }
    (*(u16*)(object + 0xA))++;
    if (fn_80180454(object + 0x24) ||
        (state[0x75] && (int)lbl_8064D18C != *(int*)(object + 0x38))) {
        *(u16*)(object + 0x22) = 8;
    }
    return 0;
}
