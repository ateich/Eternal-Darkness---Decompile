extern int lbl_8064C5E4;
extern int lbl_8064C5E8;
extern int lbl_8064C624;
extern int lbl_8064C628;
extern int lbl_8064C620;
extern unsigned int lbl_80238908[];
extern void fn_800459C0(void);
extern void fn_801E7DC8(int);
extern void fn_8011E174(int, int);
extern void fn_8011DF6C(void);

void fn_8001D91C(void) {
    if (lbl_8064C5E8 == lbl_8064C624 && lbl_8064C628 == 0) {
        return;
    }
    lbl_8064C5E4 = lbl_8064C5E8;
    lbl_8064C5E8 = lbl_8064C624;
    lbl_8064C628 = 0;
    fn_800459C0();
    fn_801E7DC8(0x223);
    fn_801E7DC8(0x100);
    fn_801E7DC8(0x223);
    fn_801E7DC8(0x100);
    lbl_8064C620 = lbl_80238908[lbl_8064C5E8 * 2 + 1];
    fn_8011E174(0x10, 1);
    fn_8011DF6C();
    if (lbl_80238908[lbl_8064C5E8 * 2] != 0) {
        fn_801E7DC8(0x223);
        fn_801E7DC8(0x100);
        ((void (*)(void))lbl_80238908[lbl_8064C5E8 * 2])();
    }
}
