extern void* lbl_8064D0F8;
extern int lbl_8064D0D4;
extern void* fn_8017CDB4(void*);
extern void fn_80157438(int, int);

void* fn_80155E68(void)
{
    void* result = fn_8017CDB4(lbl_8064D0F8);

    if (result != 0)
        lbl_8064D0D4++;
    else
        fn_80157438(9, 0);
    return result;
}
