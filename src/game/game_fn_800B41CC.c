extern void fn_800B25AC(void);
extern void fn_800B4660(int, int);
extern int fn_800B1944(void);
extern void fn_800B6840(int);
extern void fn_800B669C(int, int);

void fn_800B41CC(int value, int mode)
{
    fn_800B25AC();
    switch (mode) {
    case 0:
        fn_800B4660(value, 1);
        break;
    case 1:
    case 2:
        switch (fn_800B1944()) {
        case 0:
        case 1:
        case 3:
            fn_800B6840(value);
            break;
        case 2:
            fn_800B669C(value, 0);
            break;
        }
        break;
    }
}
