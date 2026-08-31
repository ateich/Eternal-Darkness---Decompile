extern int lbl_8064D13C;
extern int fn_8015AD40(int);
extern void fn_8016ADF0(int, int, int);
extern void fn_8016B400(int, void*, void*);

void fn_8015AC94(int index, int mode)
{
    short value = fn_8015AD40(index);

    if (value > 0 && lbl_8064D13C != 0) {
        if (mode == 0) {
            fn_8016ADF0(value, -1, 1);
        } else if (mode == 1) {
            fn_8016B400(value, 0, 0);
        }
    }
}
