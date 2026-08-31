extern int lbl_8064D294;

extern void fn_8020EC6C(int);
extern unsigned int fn_8020EBEC(void);
extern void fn_801B9078(int);

void fn_801A96A8(int mode, int apply, int notify)
{
    unsigned int state;

    if (apply != 0) {
        if (mode == 0) {
            fn_8020EC6C(0);
        } else {
            fn_8020EC6C(1);
        }
    }

    state = fn_8020EBEC();
    if (state == 0) {
        lbl_8064D294 = 0;
    } else if (state == 1) {
        if (mode == 2) {
            lbl_8064D294 = 2;
        } else {
            lbl_8064D294 = 1;
        }
    } else {
        lbl_8064D294 = 1;
    }

    if (notify != 0) {
        fn_801B9078(lbl_8064D294);
    }
}
