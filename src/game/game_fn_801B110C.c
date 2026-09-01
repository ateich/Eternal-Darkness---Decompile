extern void fn_801B1028(void);
extern void fn_802158EC(void*, int);
extern void fn_801B10A4(void*, unsigned int);
extern char lbl_8060BF00[];
extern int lbl_8064D33C;
extern void* lbl_8064D348;

void fn_801B110C(void)
{
    fn_801B1028();
    fn_802158EC(lbl_8060BF00, 0);
    lbl_8064D33C = 1;
    fn_801B10A4(lbl_8064D348, 1);
}
