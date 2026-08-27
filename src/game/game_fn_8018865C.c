typedef unsigned char u8;

extern unsigned char lbl_80606780[];
extern void* lbl_8064D250;

extern void fn_801ED468(int);
extern int fn_8017FFB8(void);
extern int fn_8017FFB0(void);
extern int fn_8017FF98(void);
extern void fn_80225F4C(int, void*, u8);
extern void fn_801ECF50(int);
extern void fn_801ECEC8(int, int, int);
extern void fn_8022B448(void*, void*);
extern void fn_80226D78(int);

void fn_8018865C(void* first, void* second, void* third)
{
    fn_801ED468(0x3C);
    fn_80225F4C(9, first, (u8)fn_8017FFB8());
    fn_80225F4C(0xD, second, (u8)fn_8017FFB0());
    fn_80225F4C(0xB, third, (u8)fn_8017FF98());
    fn_801ECF50(3);
    fn_801ECEC8(1, 3, 0);
    fn_8022B448(lbl_80606780, lbl_8064D250);
    fn_80226D78(0);
}
