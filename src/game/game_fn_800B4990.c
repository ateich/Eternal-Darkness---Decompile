extern void fn_800B25AC(void);
extern void fn_800B376C(int, int);
extern void fn_8017B074(int);
extern int fn_800B1944(void);
extern void fn_800B2548(int, int);
extern void fn_800B669C(int, int);
extern void fn_800B1974(int);

void fn_800B4990(int value, int mode)
{
    fn_800B25AC();
    switch (mode) {
    case 0:
        fn_800B376C(value, 0);
        break;
    case 1:
    case 2:
        fn_8017B074(value);
        switch (fn_800B1944()) {
        case 0:
        case 1:
            fn_800B2548(1, value);
            break;
        case 2:
            fn_800B669C(value, 0);
            break;
        case 3:
            fn_800B1974(0);
            break;
        }
        break;
    }
}
