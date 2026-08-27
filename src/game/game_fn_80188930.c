typedef unsigned char u8;

extern unsigned char lbl_80606AE0[];
extern void* lbl_8064D24C;

extern void fn_801A8D38(int);
extern int fn_8017FFB8(void);
extern int fn_8017FFB0(void);
extern int fn_8017FF98(void);
extern void fn_80225F4C(int, void*, u8);
extern void fn_801ECEC8(int, int, int);
extern void fn_8022B448(void*, void*);
extern void fn_801F03B8(void);

void fn_80188930(void* first, void* second, void* third)
{
    fn_801A8D38(3);
    fn_80225F4C(9, first, (u8)fn_8017FFB8());
    fn_80225F4C(0xB, third, (u8)fn_8017FF98());
    fn_80225F4C(0xD, second, (u8)fn_8017FFB0());
    fn_801ECEC8(1, 3, 0);
    fn_8022B448(lbl_80606AE0, lbl_8064D24C);
    fn_801F03B8();
}
