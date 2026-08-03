typedef int s32;

typedef struct ModeFunctions {
    void (*enter)(void);
    void (*frame)(void);
} ModeFunctions;

extern ModeFunctions lbl_80238908[];
extern s32 lbl_8064C5E4;
extern s32 lbl_8064C5E8;
extern void (*lbl_8064C620)(void);
extern s32 lbl_8064C624;
extern s32 lbl_8064C628;

extern void fn_800459C0(void);
extern void fn_8011DF6C(void);
extern void fn_8011E174(s32, s32);
extern void fn_801E7DC8(s32);

void fn_8001D91C(void)
{
    if (lbl_8064C5E8 != lbl_8064C624 || lbl_8064C628 != 0) {
        lbl_8064C5E4 = lbl_8064C5E8;
        lbl_8064C5E8 = lbl_8064C624;
        lbl_8064C628 = 0;
        fn_800459C0();
        fn_801E7DC8(0x223);
        fn_801E7DC8(0x100);
        fn_801E7DC8(0x223);
        fn_801E7DC8(0x100);
        lbl_8064C620 = lbl_80238908[lbl_8064C5E8].frame;
        fn_8011E174(0x10, 1);
        fn_8011DF6C();
        if (lbl_80238908[lbl_8064C5E8].enter != 0) {
            fn_801E7DC8(0x223);
            fn_801E7DC8(0x100);
            lbl_80238908[lbl_8064C5E8].enter();
        }
    }
}
