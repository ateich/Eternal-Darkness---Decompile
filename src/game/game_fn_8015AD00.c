extern int lbl_8064D138;
extern int fn_8015AD88(int);
extern void fn_8016B400(int, void*, void*);

void fn_8015AD00(int index)
{
    short value = fn_8015AD88(index);

    if (value > 0 && lbl_8064D138 != 0) {
        fn_8016B400(value, 0, 0);
    }
}
