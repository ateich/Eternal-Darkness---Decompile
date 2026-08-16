typedef unsigned char u8;
typedef unsigned int u32;

typedef struct GameState {
    u8 pad000[0x1DA];
    u8 mode;
    u8 pad1DB[6];
    signed char active;
    u8 pad1E2[2];
    signed char suppress;
} GameState;

extern GameState lbl_8030F540;
extern u32 lbl_8064F928;
extern u32 lbl_8064D6EC;
extern int lbl_8064CC20;
extern void *lbl_8064CC14;

extern void fn_800ED93C(int);
extern void fn_801F3528(u32 *);
extern void fn_801A8D38(int);
extern void fn_801F35A8(void);
extern void fn_801F3158(u32);
extern void fn_801F3240(void);
extern void fn_801EB194(int);
extern void fn_801096C4(void *);
extern void fn_80109868(void *);
extern void fn_80109AD4(void *);
extern void fn_80139940(int);
extern void fn_801358C4(void);
extern void fn_801358B4(int);
extern void fn_801B2380(int);
extern void fn_801ACC94(int);

void fn_800EE468(void)
{
    if (lbl_8030F540.active) {
        fn_800ED93C(0);
        if ((lbl_8030F540.mode == 0x25 || lbl_8030F540.mode == 0x26 ||
             lbl_8030F540.mode == 0x27) &&
            !lbl_8030F540.suppress) {
            u32 value = lbl_8064F928;
            fn_801F3528(&value);
            fn_801A8D38(6);
            fn_801F35A8();
            fn_801F3158(lbl_8064D6EC);
            fn_801F3240();
        }
        fn_801EB194(1);
    }

    if (lbl_8064CC20 != 0) {
        fn_801096C4(lbl_8064CC14);
    }
    fn_80109868(lbl_8064CC14);
    fn_80109AD4(lbl_8064CC14);

    if (lbl_8030F540.mode != 0x25 && lbl_8030F540.mode != 0x26 &&
        lbl_8030F540.mode != 0x27 && lbl_8030F540.active) {
        fn_800ED93C(0);
        fn_801EB194(1);
    }
    fn_80139940(1);
    lbl_8064CC20 = 0;
    fn_801358C4();
    fn_801358B4(1);
    fn_801B2380(1);
    fn_801ACC94(1);
}
