typedef unsigned char u8;

extern void fn_801CE2B8(void);
extern void fn_801CE280(void);
extern void fn_801B8164(int, int, int, int, int);

void fn_801B8FE4(int arg0, int arg1, u8 arg2, u8 arg3)
{
    fn_801CE2B8();
    if (arg2) {
        fn_801B8164(arg0, arg1, 0x15, 0, -1);
    }
    if (arg3) {
        fn_801B8164(arg0, arg1, 0x16, 0, -1);
    }
    fn_801CE280();
}
