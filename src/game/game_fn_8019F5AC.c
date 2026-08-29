typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
extern int lbl_8064D18C;

extern int fn_8018F0A0(void);
extern int fn_80180430(void*, u8);
extern void fn_8017E1E4(void*, void*, int, int);
extern void fn_8018E230(void*, void*, int, u8, u8, int);
extern int fn_8019F6F0(void*);

int fn_8019F5AC(u8* object)
{
    int direction;
    u8* entry;
    int count;
    int i;

    direction = fn_8018F0A0();
    entry = *(u8**)(object + 0x4C);
    count = object[1];
    for (i = 0; i < count; i++) {
        if (fn_80180430(object + 0x24, (u8)i)) {
            fn_8017E1E4(entry + 0xA, entry + 0x10, 4, direction ? -1 : 1);
            if (direction) {
                if (*(s16*)(entry + 0xE) < *(s16*)(object + 0x8C)) {
                    fn_8018E230(entry, entry + 0x2B, 1, object[2], object[4], 0);
                    *(int (**)(void*))(object + 0x14C) = fn_8019F6F0;
                }
            } else if (*(s16*)(entry + 0xE) > *(s16*)(object + 0x8C)) {
                fn_8018E230(entry, entry + 0x2B, 1, object[2], object[4], 0);
                *(int (**)(void*))(object + 0x14C) = fn_8019F6F0;
            }
        } else {
            *(u16*)(object + 0x22) = 8;
        }
        entry += 0x38;
    }
    (*(u16*)(object + 0xA))++;
    if (lbl_8064D18C != *(int*)(object + 0x38) ||
        *(u16*)(object + 0xA) >= *(u16*)(object + 0xC)) {
        *(u16*)(object + 0x22) = 8;
    }
    return 0;
}
