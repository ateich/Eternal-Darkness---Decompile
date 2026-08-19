extern void (*lbl_8064D14C)(int, int);
extern int lbl_8064D18C;

void fn_8015AC3C(int value)
{
    if (lbl_8064D14C != 0) {
        lbl_8064D14C(lbl_8064D18C, value);
    }
}
