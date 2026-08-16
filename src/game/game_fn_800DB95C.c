extern int fn_80047CB4(void);
extern int fn_8011EB04(void *);
extern void fn_80047FFC(int);
extern void fn_80047D90(void);

void fn_800DB95C(void *object)
{
    int kind = fn_80047CB4();

    if (fn_8011EB04(object) != kind) {
        return;
    }
    fn_80047FFC(1);
    fn_80047D90();
}
