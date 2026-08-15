extern unsigned char lbl_8032072C[];

extern int fn_800B25F4(void);
extern int fn_800B194C(void);
extern void fn_800B23FC(int);
extern void fn_801E8E68(void*, int);
extern void fn_800B1AE4(int, int);

void fn_800B2548(int arg0, int arg1)
{
    if (fn_800B25F4() == 0) {
        fn_800B23FC(fn_800B194C());
    }
    fn_801E8E68(lbl_8032072C, arg0);
    fn_800B1AE4(arg0, arg1);
}
