extern void fn_800B25AC(void);
extern void fn_800B1974(int);

void fn_800B4028(int mode)
{
    fn_800B25AC();
    switch (mode) {
    case 0:
        fn_800B1974(1);
        break;
    case 1:
        fn_800B1974(0);
        break;
    case 2:
        fn_800B1974(-1);
        break;
    }
}
