extern int lbl_8064CFFC;
extern int lbl_8064D000;
extern void* lbl_8064D004;

extern void* fn_801397F8(void*, int, int, int);

void fn_801388F8(int mode)
{
    if (mode == 1) {
        lbl_8064D004 = fn_801397F8(&lbl_8064CFFC, 2, 2, 1);
        lbl_8064D000 = 0;
    } else {
        lbl_8064D004 = 0;
        lbl_8064CFFC = 0;
        lbl_8064D000 = 0;
    }
}
