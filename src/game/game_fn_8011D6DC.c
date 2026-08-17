extern int lbl_8064CCA0;
extern unsigned char lbl_80332158[];

extern void fn_800AFBA8(void*);
extern void fn_800B18F8(void);
extern void fn_80109B94(void);
extern void fn_8011D698(void);
extern void fn_801E8B24(int, int, int);

void fn_8011D6DC(void)
{
    fn_800B18F8();
    fn_800AFBA8(lbl_80332158 + 8);
    fn_8011D698();
    fn_80109B94();
    fn_801E8B24(lbl_8064CCA0, 2, 0);
}
