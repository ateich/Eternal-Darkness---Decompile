typedef unsigned char u8;
typedef unsigned short u16;

extern int lbl_8064D18C;

extern int fn_8018F0A0(void);
extern int fn_80180430(void*, u8);
extern void fn_8017E1E4(void*, void*, int, int);
extern u8 fn_8018E26C(void*, void*);
extern void fn_80180518(void*, u8, int);

int fn_8019F6F0(u8* object)
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
            if (entry[0] == 1 && fn_8018E26C(entry, entry + 0x2B) == 0 &&
                entry[0x2B] == 0 && entry[1] == 0) {
                fn_80180518(object + 0x24, (u8)i, 0);
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
