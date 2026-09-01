extern volatile unsigned int lbl_8064D328;
extern int lbl_8064D33C;

extern void fn_801B1740(void*);
extern void fn_8021A140(void*);
extern void fn_8021A184(void);
extern void fn_8021A1A8(int);
extern void fn_8021A468(int);
extern void fn_8021A494(int);

void fn_801B14B8(void)
{
    fn_8021A468(0);
    fn_8021A494(0);
    fn_8021A140(0);
    fn_8021A184();
    fn_8021A1A8(0);
    lbl_8064D328 = 1;
    fn_801B1740(0);
    lbl_8064D33C = 0;
    while (lbl_8064D328 != 0) {
    }
}
