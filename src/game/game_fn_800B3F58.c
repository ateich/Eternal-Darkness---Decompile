extern int fn_800B7EC0(void);
extern void fn_800B25AC(void);
extern void fn_800B2548(int, int);
extern void fn_800B1974(int);

void fn_800B3F58(int mode)
{
    int value = fn_800B7EC0();

    fn_800B25AC();
    switch (mode) {
    case 0:
        fn_800B2548(1, value);
        break;
    case 1:
    case 2:
        fn_800B1974(0);
        break;
    }
}
