typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int fn_8018037C(void*);
extern void fn_80180374(void*, u8);
extern void fn_8017FE14(void*, void*);
extern int fn_801A260C(void*);

void fn_801A29E0(u8* object)
{
    int count;
    u32 zero;
    zero = 0;

    *(u16*)(object + 0xA) = zero;
    *(u16*)(object + 0xC) = 100;
    *(u32*)(object + 0x44) = zero;
    count = fn_8018037C(object);
    fn_80180374(object, (u8)(count < 10 ? count : 10));
    fn_8017FE14(object, fn_801A260C);
}
