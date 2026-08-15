extern int fn_800B25F4(void);
extern void fn_800B25AC(void);
extern void fn_8017B074(int);
extern void fn_800B16F4(void);

void fn_800B18F8(void)
{
    while (fn_800B25F4() == 0) {
        fn_800B25AC();
    }
    fn_8017B074(0);
    fn_8017B074(1);
    fn_800B16F4();
}
