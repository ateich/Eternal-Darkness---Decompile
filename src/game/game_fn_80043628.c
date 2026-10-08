typedef unsigned int u32;

extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32);
extern void *fn_80201B9C(void);
extern void *fn_80201BC0(void *);
extern void *fn_80201BC8(void *);
extern int fn_80201B4C(void *);
extern int fn_80201EB8(void *);
extern u32 fn_8011FAEC(void *);
extern void *fn_8011F950(void *);
extern void fn_8011F948(void *, void *);
extern void *fn_80155DB4(void *);
extern int fn_8002A858(void *, void *, int);
extern int lbl_8064D18C;

void fn_80043628(void)
{
    void *object;
    u32 interrupts;
    void *runtime;
    u32 flags;

    object = fn_80201B9C();
    interrupts = OSDisableInterrupts();
    while (object != 0) {
        runtime = fn_80201BC8(object);
        if (fn_80201B4C(object) != -1) {
            fn_80201EB8(object);
            if (runtime != 0) {
                flags = fn_8011FAEC(runtime);
                if (fn_8011F950(runtime) != 0 && (flags & 0x8000) == 0) {
                    fn_8002A858(fn_80155DB4(object), runtime, lbl_8064D18C);
                    fn_8011F948(runtime, 0);
                }
            }
        }
        object = fn_80201BC0(object);
    }
    OSRestoreInterrupts(interrupts);
}
