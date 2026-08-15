extern void fn_800B25AC(void);
extern void fn_800B1974(int);

void fn_800B3FC4(int mode)
{
    fn_800B25AC();
    if (mode == 0) {
        fn_800B1974(1);
    } else if (mode == 1) {
        fn_800B1974(0);
    } else if (mode == 2) {
        fn_800B1974(-1);
    }
}
