extern int lbl_8064CB20;
extern void fn_800EB5F4(int, int);

void fn_800EB6BC(void)
{
    int type;
    int index = 0;

    type = lbl_8064CB20;
    while (type < 5) {
        fn_800EB5F4(type, index);
        type++;
        index++;
    }

    if (lbl_8064CB20 != 0) {
        type = 0;
        while (type < lbl_8064CB20) {
            fn_800EB5F4(type, index);
            type++;
            index++;
        }
    }
}
