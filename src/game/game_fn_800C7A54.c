extern void *fn_80201B94(void *);
extern void *fn_80201BC8();
extern void *fn_80201C48(void *);
extern void *fn_80201814();
extern int fn_8011EB04(void *);
extern int fn_8011F598(void *, int, int, int, void *, int);
extern void fn_8011F0E8(void *, void *);

void fn_800C7A54(void *object)
{
    void *runtime;
    void *parent;
    char search[8];
    char output[40];

    parent = fn_80201B94(object);
    runtime = fn_80201BC8(object);

    if (fn_8011EB04(runtime) != 0xFB &&
        fn_8011F598(runtime, 2, 15, -1, search, 1) != -1) {
        void *other = fn_80201814(fn_80201C48(parent));
        if (other != 0) {
            fn_8011F0E8(fn_80201BC8(other), output);
        }
    }
}
