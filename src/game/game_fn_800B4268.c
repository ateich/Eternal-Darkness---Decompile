extern void fn_800B25AC(void);
extern int fn_800B1944(void);
extern void fn_800B6840(int);
extern int fn_800B6908(void);
extern void fn_800B5D94(int);
extern void fn_800B669C(int, int);
extern void fn_800B1974(int);

void fn_800B4268(int value)
{
    fn_800B25AC();
    switch (fn_800B1944()) {
    case 0:
        fn_800B6840(value);
        break;
    case 1:
        if (fn_800B6908() == 1) {
            fn_800B5D94(value);
        } else {
            fn_800B6840(value);
        }
        break;
    case 2:
        fn_800B669C(value, 0);
        break;
    case 3:
        fn_800B1974(0);
        break;
    }
}
