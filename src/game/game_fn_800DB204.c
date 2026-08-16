extern void fn_80201BC8(void *);
extern int fn_8011FAEC(void);
extern void *fn_80201C24(void *);
extern int fn_80157894(void *);
extern void **fn_80047D6C(void);
extern int fn_80201B54(void *);
extern void fn_8020123C(int, int, int, void **);
extern void fn_80157B6C(void *, int);
extern int fn_801579F4(void *);
extern void *fn_80201814(void);
extern void fn_800DB37C(void *, int);
extern void fn_800DBA0C(void *, int);

void fn_800DB204(void *context)
{
    void *object;
    void **active;
    int owner;

    fn_80201BC8(context);
    if ((fn_8011FAEC() & 0x4000) == 0) {
        object = fn_80201C24(context);
        if ((fn_80157894(object) & 2) != 0) {
            active = fn_80047D6C();
            owner = fn_80201B54(context);
            fn_8020123C(0x4A, owner, owner, active);
            fn_80157B6C(object, 2);
            if (fn_801579F4(object) > 0) {
                context = fn_80201814();
                fn_800DB37C(context, 1);
                fn_800DBA0C(context, 0);
            }
        }
    }
}
