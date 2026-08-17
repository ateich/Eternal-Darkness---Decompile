extern int lbl_8064C4E4;
extern void fn_801FA4F0(int, int);
extern void fn_801F6ED0(int, int);
extern void fn_8013B83C(int);
extern int fn_801261F4(int);
extern void fn_8011F7E0(int, int);

void fn_800A5330(int object)
{
    fn_801FA4F0(2, 1);
    fn_801F6ED0(lbl_8064C4E4, object);
    lbl_8064C4E4 = object;
    fn_8013B83C(object);
    fn_801261F4(lbl_8064C4E4);
    fn_8011F7E0(lbl_8064C4E4, 0);
}
