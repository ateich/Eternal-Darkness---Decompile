extern unsigned char lbl_8032EA10[];
extern void fn_8020D250(void*, int, int);

void fn_80108BD4(int status)
{
    if (status == -1) {
        fn_8020D250(lbl_8032EA10, 6, 0);
    } else {
        fn_8020D250(lbl_8032EA10, 1, 0);
    }
}
