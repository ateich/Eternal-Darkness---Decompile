extern void fn_800B25AC(void);
extern int fn_800B1944(void);
extern void fn_800B6718(int);
extern void fn_800B2548(int, int);
extern void fn_800B6840(int);
extern void fn_800B1974(int);

void fn_800B3898(int value, int mode)
{
    fn_800B25AC();
    switch (mode) {
    case 0:
        switch (fn_800B1944()) {
        case 0:
        case 1:
        case 2:
            fn_800B6718(value);
            break;
        case 3:
            fn_800B2548(2, 0);
            break;
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
