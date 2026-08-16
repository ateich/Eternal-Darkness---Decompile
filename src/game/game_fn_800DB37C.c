extern void *fn_80201BC8();
extern void *fn_80155DB4(void *);
extern int fn_8011EB04(void *);
extern void fn_801284B0(void *, int, int);
extern void fn_8011FA8C(void *, int, int);
extern void fn_801568C0(void *, void *);
extern void fn_800DA8D4(void);

void fn_800DB37C(void *context, int force)
{
    void *object;
    void *action;
    int kind = 1;

    object = fn_80201BC8(context);
    action = fn_80155DB4(context);
    if (force == 0 && (fn_8011EB04(object) == 0xC1 || fn_8011EB04(object) == 0xE6)) {
        kind = 9;
    }
    fn_801284B0(object, kind, 0xF);
    fn_8011FA8C(object, 0, 0x802);
    fn_801568C0(action, fn_800DA8D4);
}
