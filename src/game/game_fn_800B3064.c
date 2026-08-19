extern int lbl_803003C8[];
extern int lbl_8064C578;
extern int lbl_8064C4E0;
extern int lbl_8064D18C;
extern int lbl_8064CA40;

extern int fn_800B6908(void);
extern void fn_800B25AC(void);
extern void fn_800B1974(int);
extern void fn_800B2548(int, int);
extern int fn_801E79FC(void*, int);
extern void fn_800DE354(void);
extern void* fn_80201890(void);
extern int fn_8011FB4C(void);

void fn_800B3064(int mode)
{
    int state;

    state = fn_800B6908();
    fn_800B25AC();
    switch (mode) {
    case 0:
        fn_800B1974(0);
        break;
    case 1:
        if (state == 1) {
            fn_800B2548(1, -1);
        } else if (lbl_803003C8[2] == 9 && lbl_8064C578 < 4 &&
                   fn_801E79FC((void *)lbl_8064C4E0, 0x206) != 0) {
            fn_800DE354();
            if (fn_80201890() != 0 && lbl_8064D18C == fn_8011FB4C()) {
                fn_800B2548(0x5D, -1);
            } else {
                fn_800B2548(0x5C, -1);
            }
        } else if (lbl_8064CA40 != 0) {
            fn_800B2548(1, -1);
        } else {
            fn_800B2548(0x5B, -1);
        }
        break;
    }
}
