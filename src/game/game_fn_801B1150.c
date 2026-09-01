extern void fn_801B1070(void);
extern void fn_802158EC(void*, int);
extern void fn_801B10A4(void*, unsigned int);
extern char lbl_8060BF30[];
extern int lbl_8064D33C;
extern void* lbl_8064D348;

void fn_801B1150(void)
{
    fn_801B1070();
    fn_802158EC(lbl_8060BF30, 0);
    lbl_8064D33C = 2;
    fn_801B10A4(lbl_8064D348, 0x20);
}
