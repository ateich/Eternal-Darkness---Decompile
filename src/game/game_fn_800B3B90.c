extern int lbl_8064CA64;
extern int lbl_8064CA60;
extern char lbl_80247434[];

extern void fn_800B25AC(void);
extern int fn_8017B32C(int);
extern int fn_800BC028(int);
extern void fn_800B2548(int, int);
extern void fn_8017B294(int);
extern void fn_800B261C(int);
extern void fn_800B5B4C(void);
extern void fn_800B2624(int, int, void*, int, void (*)(void));
extern int fn_800B1944(void);
extern void fn_800B6840(int);
extern void fn_800B669C(int, int);

void fn_800B3B90(int value, int mode)
{
    fn_800B25AC();
    switch (mode) {
    case 0:
        if (fn_8017B32C(value) == 0) {
            if (fn_800BC028(value) != 0) {
                fn_800B2548(0x57, value);
            }
        } else {
            fn_8017B294(value);
            fn_800B261C(0);
            lbl_8064CA64 = 1;
            lbl_8064CA60 = 0;
            fn_800B2624(8, value, lbl_80247434, 1, fn_800B5B4C);
        }
        break;
    case 1:
        if (fn_800B1944() != 2) {
            fn_800B6840(value);
        } else {
            fn_800B669C(value, 0);
        }
        break;
    }
}
