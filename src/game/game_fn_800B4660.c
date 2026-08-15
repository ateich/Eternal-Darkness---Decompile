extern void fn_800B25AC(void);
extern int fn_8017B32C(int);
extern void fn_8017B074(int);
extern int fn_800AF7E4(int, int*);
extern void fn_800B261C(int);
extern void fn_800B19A4(void);
extern void fn_8017B31C(void (*)(void));
extern void fn_800B4B74(void);
extern void fn_800B2624(int, int, int, int, void (*)(void));
extern void fn_800B2548(int, int);
extern void fn_800B5E90(int, int);
extern int fn_800B1944(void);
extern void fn_800B6718(int);
extern void fn_800B65E4(int);

void fn_800B4660(int value, int mode)
{
    fn_800B25AC();
    switch (mode) {
    case 1: {
        int output;

        if (fn_8017B32C(value) != 0) {
            fn_8017B074(value);
        }
        switch (fn_800AF7E4(value, &output)) {
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
    }
    case 0: {
        int output;

        switch (fn_800B1944()) {
        case 0:
        case 1:
        case 3:
            if (fn_8017B32C(value) == 0) {
                switch (fn_800AF7E4(value, &output)) {
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
            } else {
                fn_800B6718(value);
            }
            break;
        case 2:
            fn_800B65E4(value);
            break;
        }
        break;
    }
    }
}
