extern int lbl_8064CDC8;
extern int lbl_8064CA68;

extern int fn_800B6908(void);
extern void fn_800B25AC(void);
extern int fn_800B1944(void);
extern void fn_800B1974(int);
extern void fn_800B2548(int, int);
extern int fn_800AF7E4(int, int*);
extern void fn_800B261C(int);
extern void fn_800B19A4(void);
extern void fn_8017B31C(void (*)(void));
extern void fn_800B4B74(void);
extern void fn_800B2624(int, int, int, int, void (*)(void));
extern void fn_800B5E90(int, int);
extern void fn_800B65E4(int);

void fn_800B3178(int value, int mode)
{
    int output;
    int result;

    fn_800B6908();
    fn_800B25AC();
    switch (mode) {
    case 0:
        switch (fn_800B1944()) {
        case 0:
            if (lbl_8064CDC8 != 3) {
                fn_800B1974(0);
            } else {
                fn_800B2548(0, value);
            }
            break;
        case 1:
            if (lbl_8064CA68 != 0) {
                fn_800B2548(0xC, 0);
            } else {
                fn_800B1974(0);
            }
            break;
        case 3:
            fn_800B1974(0);
            break;
        }
        break;
    case 1:
        switch (fn_800B1944()) {
        case 0:
        case 1:
        case 3:
            result = fn_800AF7E4(value, &output);
            switch (result) {
            case 1:
                fn_800B261C(1);
                fn_8017B31C(fn_800B19A4);
                fn_800B2624(1, value, 0, 0, fn_800B4B74);
                break;
            case -2:
                fn_800B2548(0x28, value);
                break;
            case -1:
                fn_800B5E90(value, output);
                break;
            }
            break;
        case 2:
            fn_800B65E4(value);
            break;
        }
        break;
    }
}
