extern void* lbl_8064CDBC;
extern unsigned char lbl_8024B560[];
extern void fn_80144C40(void);
extern void fn_80144680(void*);
extern void* fn_80144628(int, void*, int);

void fn_8010C1CC(void)
{
    fn_80144C40();
    if (lbl_8064CDBC != 0) {
        fn_80144680(lbl_8064CDBC);
        lbl_8064CDBC = 0;
    } else {
        lbl_8064CDBC = fn_80144628(7, lbl_8024B560, 0);
    }
}
