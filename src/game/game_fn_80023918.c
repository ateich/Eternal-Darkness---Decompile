typedef unsigned char u8;
typedef unsigned int u32;

extern u32 lbl_8030241C[];
extern u8 lbl_803026DC[];
extern u32 lbl_8064B2C0;
extern u32 lbl_8064C650;
extern int lbl_8064C6BC[2];
extern u32 lbl_8064C6C4;

extern void fn_800B18F8(void);
extern void fn_800AFBA8(u8*);
extern void fn_8001DE84(int, int);
extern u32 fn_801A98F4(int, int);
extern void fn_800B177C(int, void (*)(int));
extern void fn_800B689C(int, int);
extern void fn_800B2548(int, int);
extern void fn_8001DE68(void);
extern void fn_80023800(int);

void fn_80023918(int mode)
{
    fn_800B18F8();

    if ((lbl_8064C6C4 & 2) || mode == -1) {
        if (mode == -1) {
            lbl_8064C6C4 = 0;
        }
        fn_8001DE68();
    } else if (mode == 1) {
        fn_800AFBA8(lbl_803026DC);
        fn_8001DE84(0xE, 0);
        lbl_8064B2C0 = 0;
        lbl_8030241C[10] = 7;
        lbl_8064C650 = fn_801A98F4(0x2D3, 100);
    } else if (mode == 0) {
        if (lbl_8064C6BC[0] == 0 && lbl_8064C6BC[1] == 0) {
            fn_800B177C(3, fn_80023800);
            fn_800B689C(1, 1);
            fn_800B2548(0xD, 0);
        } else if ((lbl_8064C6BC[0] == 2 || lbl_8064C6BC[0] == 0) &&
                   (lbl_8064C6BC[1] == 2 || lbl_8064C6BC[1] == 0)) {
            fn_800B177C(3, fn_80023800);
            fn_800B689C(1, 1);
            fn_800B2548(0xE, 0);
        } else {
            fn_80023800(1);
        }
    }
}
