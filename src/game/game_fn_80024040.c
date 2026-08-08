typedef int s32;

typedef struct GameConfig {
    s32 pad00[2];
    s32 value;
} GameConfig;

extern s32 lbl_806518F4;
extern GameConfig lbl_80302400;
extern s32 lbl_8064CBA4;
extern s32 lbl_8064C66C;
extern void* lbl_8064C500;
extern void* lbl_8064C504;
extern void* lbl_8064C50C;

extern void fn_801F3528(s32*);
extern void fn_800AFC30(GameConfig*);
extern void fn_801E6EB0(void*, s32, s32);
extern void fn_801AD404(s32, s32, s32);
extern void fn_801AD4B4(s32, s32, s32, s32);
extern void fn_801A99B4(void);
extern s32 fn_801AD898(void);
extern void fn_8001E604(void);

void fn_80024040(void)
{
    s32 value = lbl_806518F4;

    fn_801F3528(&value);
    lbl_8064C66C = lbl_80302400.value != lbl_8064CBA4;
    fn_800AFC30(&lbl_80302400);
    fn_801E6EB0(lbl_8064C500, 0x4000, 1);
    fn_801E6EB0(lbl_8064C504, 0x4000, 1);
    fn_801E6EB0(lbl_8064C50C, 0x4000, 1);
    fn_801AD404(100, 100, 1);
    fn_801AD4B4(105, 0, 1, 0);
    while (fn_801AD898() == 0) {
        fn_801A99B4();
    }
    fn_8001E604();
}
