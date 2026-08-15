typedef unsigned char u8;

extern u8 lbl_80320738[];
extern int lbl_8064CA64;
extern int lbl_8064CA60;
extern int lbl_8064CA6C;
extern char lbl_80247434[];

extern void fn_800B25AC(void);
extern int fn_800B6A24(void);
extern void fn_8017B8BC(int);
extern void fn_8017B96C(int);
extern void fn_800B261C(int);
extern void fn_800B5144(void);
extern void fn_800B2624(int, int, void*, int, void (*)(void));
extern void fn_800B2548(int, int);

void fn_800B34CC(int value, int mode)
{
    int offset;

    fn_800B25AC();
    switch (mode) {
    case 0:
        offset = fn_800B6A24();
        fn_8017B8BC(0x4000);
        fn_8017B96C((lbl_80320738[offset + 0x1B0] << 14) + 0x2000);
        lbl_8064CA64 = 1;
        lbl_8064CA60 = 0;
        fn_800B261C(0);
        fn_800B2624(7, value, lbl_80247434, 3, fn_800B5144);
        break;
    case 1:
        if (lbl_8064CA6C != 0) {
            fn_800B2548(3, value);
        } else {
            fn_800B2548(1, value);
        }
        break;
    }
}
