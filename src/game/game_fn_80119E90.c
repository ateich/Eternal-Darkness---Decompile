extern void *lbl_8064CDC0;
extern void *lbl_8064CDB4;
extern void *lbl_8064CDB0;
extern void fn_80144680(void *);
extern void fn_801E5FB0(void *);

void fn_80119E90(void)
{
    fn_80144680(lbl_8064CDC0);
    fn_801E5FB0(lbl_8064CDB4);
    lbl_8064CDB4 = 0;
    fn_801E5FB0(lbl_8064CDB0);
    lbl_8064CDB0 = 0;
}
