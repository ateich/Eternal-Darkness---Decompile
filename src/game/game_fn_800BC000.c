extern int lbl_8064CA60;
extern int lbl_8064CA64;

void fn_800BC000(void)
{
    if (lbl_8064CA60 > 0 && --lbl_8064CA60 <= 0) {
        lbl_8064CA60 = 0;
        lbl_8064CA64 = 0;
    }
}
