typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void fn_8018E230(u8*, u8*, int, u8, u8, int);
extern u8 fn_8018E26C(u8*, u8*);

u32 fn_8018385C(u8* self)
{
    u8* entry = *(u8**)(self + 0x4C);

    if (self[0x90] == 0) {
        entry[0x23]++;
        self[0x90] = self[0x8F];
    } else {
        self[0x90]--;
    }
    if (*(u16*)(self + 0xA) == *(u16*)(self + 0xC)) {
        fn_8018E230(self + 0x60, self + 0x5F, 1, self[2], self[4], 0);
    } else if (self[0x60] != 0 && !fn_8018E26C(self + 0x60, self + 0x5F)) {
        *(u16*)(self + 0x22) = 8;
    }
    (*(u16*)(self + 0xA))++;
    return 0;
}
