typedef unsigned char u8;
typedef unsigned int u32;

extern u8 fn_8018E26C(u8*, u8*);
extern void fn_8018385C(void);

u32 fn_801837D8(u8* self)
{
    u8* entry = *(u8**)(self + 0x4C);

    entry[0x22] += self[0x8D];
    if (entry[0x22] > self[0x8C]) {
        entry[0x22] = self[0x8C];
    }
    entry[0x23] += self[0x8E];
    if (!fn_8018E26C(self + 0x60, self + 0x5F)) {
        *(void (**)(void))(self + 0x14C) = fn_8018385C;
    }
    return 0;
}
