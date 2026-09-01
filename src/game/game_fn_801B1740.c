typedef unsigned int u32;

extern volatile u32 lbl_8064D33C;
extern void* lbl_8064D320;
extern unsigned char lbl_8060BFC0[9];

extern void fn_801B138C(int, int);
extern void fn_80215830(void*, void (*)(int, int));

void fn_801B1740(void* callback)
{
    u32 old_state;

    if (lbl_8064D33C != 3) {
        old_state = lbl_8064D33C;
        lbl_8064D33C = 3;
        lbl_8064D320 = callback;
        if (old_state == 1) {
            fn_80215830(lbl_8060BFC0, fn_801B138C);
        } else {
            fn_801B138C(0, 0);
        }
    }
}
