extern int lbl_8064CA64;
extern int lbl_8064CA60;

extern void fn_800B25AC(void);
extern int fn_8017B32C(int);
extern int fn_800BC028(int);
extern void fn_800B2548(int, int);
extern void fn_800B261C(int);
extern void fn_800B5A84(void);
extern void fn_800B2624(int, int, void*, int, void (*)(void));
extern void fn_800B4660(int, int);
extern int fn_800B1944(void);
extern void fn_800B6840(int);
extern void fn_800B669C(int, int);
extern void fn_800B1974(int);

void fn_800B3DB0(int value, int mode)
{
    fn_800B25AC();
    switch (mode) {
    case 0:
        if (fn_8017B32C(value) == 0) {
            if (fn_800BC028(value) != 0) {
                fn_800B2548(0x58, value);
            }
        } else {
            fn_800B261C(0);
            lbl_8064CA64 = 1;
            lbl_8064CA60 = 0;
            fn_800B2624(4, value, 0, 1, fn_800B5A84);
        }
        break;
    case 1:
        fn_800B4660(value, 1);
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
    }
}
