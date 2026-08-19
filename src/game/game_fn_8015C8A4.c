extern unsigned int lbl_8064D148;
extern float lbl_80650630;
extern int fn_80201B44();
extern void *fn_80201814();
extern int fn_80201EB8();
extern void fn_80200EAC(int, int, int, float, int);

void fn_8015C8A4(unsigned int mask, int enabled)
{
    unsigned int value = lbl_8064D148 & ~mask;
    int handle;

    if (enabled)
        value = lbl_8064D148 | mask;
    lbl_8064D148 = value;

    if (value != 0) {
        handle = fn_80201B44();
        fn_80201814();
        fn_80200EAC(0x66, handle, 0, lbl_80650630, fn_80201EB8());
    }
}
