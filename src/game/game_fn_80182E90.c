typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;

extern u8 fn_8018E26C(u8*, u8*);
extern void fn_80180518(u8*, u8, int);
extern int fn_80180430(u8*, u8);
extern void fn_8017E1E4(u8*, u8*, u8, u8);
extern void fn_8018E230(u8*, u8*, int, u8, u8, int);
extern int fn_80180454(u8*, u16);

int fn_80182E90(u8* self)
{
    int count;
    u8* entry = *(u8**)(self + 0x4C);
    int i;

    count = self[1];
    for (i = 0; i < count; entry += 0x38, i++) {
        if (entry[0] != 0 && fn_8018E26C(entry, entry + 0x2B) == 0) {
            fn_80180518(self + 0x24, (u8)i, 0);
        }
        if (fn_80180430(self + 0x24, (u8)i) != 0) {
            fn_8017E1E4(entry + 0xA, entry + 0x10, self[0x8F], self[0x90]);
            if (entry[0] == 0 && *(s16*)(entry + 0xE) > *(s16*)(self + 0x8C)) {
                fn_8018E230(entry, entry + 0x2B, 1, self[2], self[4], 0);
            }
        }
    }

    if (fn_80180454(self + 0x24, (*(u16*)(self + 0xA))++) != 0) {
        *(s16*)(self + 0x22) = 8;
    }
    return 0;
}
