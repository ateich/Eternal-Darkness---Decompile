typedef unsigned char u8;

extern void fn_80125ECC(void *);
extern void fn_8012C108(u8*);

void fn_8012C0A8(u8* owner)
{
    int offset;
    int i;

    fn_80125ECC(owner);
    i = 0;
    offset = 0;
    for (; i < 12; i++, offset += 0x90)
        fn_8012C108(*(u8**)(owner + 0x23C) + offset);
}
