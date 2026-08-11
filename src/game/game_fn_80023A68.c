typedef unsigned int u32;

extern u32 lbl_8030241C[];
extern void* lbl_8064C674;
extern u32 lbl_8064C694;
extern int lbl_8064C6C8;

extern unsigned int fn_801A98F4(int, int);
extern void fn_800472B0(int);
extern void fn_801E7004(void);
extern void fn_8001DFEC(int, int);
extern void fn_8001DE84(int, int);
extern void fn_80025A78(int);
extern void fn_801E5FB0(void*);
#define fn_801E5FB0(a) fn_801E5FB0((void*)(a))

extern void fn_801AD404(int, int, int);
extern void fn_801AD490(void);

void fn_80023A68(void)
{
    lbl_8030241C[14] = fn_801A98F4(0x278, 100);
    fn_800472B0(0);
    lbl_8030241C[10] = 5;
    fn_801E7004();

    if (lbl_8064C694 >= 0x21) {
        fn_8001DFEC(0x1F, 0);
        fn_8001DE84(0x1D, 0);
    } else {
        if (lbl_8064C6C8 != 0) {
            fn_80025A78(1);
        }
        fn_8001DFEC(0x1D, 0);
        fn_8001DE84(7, 4);
    }

    if (lbl_8064C674 != 0) {
        fn_801E5FB0(lbl_8064C674);
    }

    fn_801AD404(0, 0, 0x1E);
    fn_801AD490();
    fn_801AD404(100, 100, 1);
}
