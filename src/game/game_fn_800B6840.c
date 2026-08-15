extern int lbl_8064CA6C;

extern void fn_8017B074(int);
extern int fn_800B1944(void);
extern void fn_800B2548(int, int);

void fn_800B6840(int value)
{
    fn_8017B074(value);
    lbl_8064CA6C = 0;
    if (fn_800B1944() == 2) {
        fn_800B2548(2, value);
    } else {
        fn_800B2548(1, value);
    }
}
