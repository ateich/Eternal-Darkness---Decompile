extern void fn_800B25AC(void);
extern int fn_8017B32C(int);
extern int fn_800BC028(int);
extern void fn_800B2548(int, int);
extern void fn_800B4660(int, int);
extern int fn_800B1944(void);
extern void fn_800B6840(int);
extern void fn_800B669C(int, int);
extern void fn_800B1974(int);
extern void OSResetSystem(int, int, int);

void fn_800B39A8(int value, int mode)
{
    fn_800B25AC();
    switch (mode) {
    case 1:
        OSResetSystem(1, 0, 1);
        break;
    case 0:
        if (fn_8017B32C(value) == 0) {
            if (fn_800BC028(value) != 0) {
                fn_800B2548(0x56, value);
            }
        } else {
            fn_800B4660(value, 0);
        }
        break;
    case 3:
        switch (fn_800B1944()) {
        case 0:
        case 1:
            fn_800B6840(value);
            break;
        case 2:
            fn_800B669C(value, 0);
            break;
        case 3:
            fn_800B1974(0);
            break;
        }
        break;
    case 2:
        switch (fn_800B1944()) {
        case 0:
        case 1:
            fn_800B6840(value);
            break;
        case 2:
            fn_800B669C(value, 0);
            break;
        case 3:
            fn_800B1974(1);
            break;
        }
        break;
    }
}
