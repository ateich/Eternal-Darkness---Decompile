extern void fn_800B25AC(void);
extern int fn_8017B32C(int);
extern int fn_800BC028(int);
extern void fn_800B2548(int, int);
extern int fn_800B1944(void);
extern void fn_800B6718(int);
extern void fn_800B6840(int);
extern void fn_800B1974(int);

void fn_800B376C(int value, int mode)
{
    int state;

    fn_800B25AC();
    switch (mode) {
    case 0:
        if (fn_8017B32C(value) == 0) {
            if (fn_800BC028(value) != 0) {
                fn_800B2548(0x56, value);
            }
        } else {
            state = fn_800B1944();
            switch (state) {
            case 0:
            case 1:
            case 2:
            case 3:
                fn_800B6718(value);
                break;
            }
        }
        break;
    case 1:
        switch (fn_800B1944()) {
        case 0:
        case 1:
            fn_800B6840(value);
            break;
        case 3:
            fn_800B1974(1);
            break;
        }
        break;
    case 2:
        switch (fn_800B1944()) {
        case 0:
        case 1:
            fn_800B6840(value);
            break;
        case 3:
            fn_800B1974(0);
            break;
        }
        break;
    }
}
