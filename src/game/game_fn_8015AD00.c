extern int lbl_8064D138;
extern int fn_8015AD88(int);
extern void fn_8016B400(int, int, int);

void fn_8015AD00(int index)
{
    int value = fn_8015AD88(index);

    if ((short)value > 0 && lbl_8064D138 != 0) {
        fn_8016B400(value, 0, 0);
    }
}
