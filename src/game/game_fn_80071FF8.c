extern void *fn_80201B9C();
extern int fn_80201EB8(void *);
extern void *fn_80201B8C();
extern void *fn_80201BC8();
extern void *fn_80201BC0(void *);
extern void fn_8011FB54(void *, int);

void fn_80071FF8(int value)
{
    void *object = fn_80201B9C();

    while (object != 0) {
        if (fn_80201EB8(object) == 0x2710) {
            fn_80201B8C(object);
            fn_8011FB54(fn_80201BC8(object), value);
        }
        object = fn_80201BC0(object);
    }
}
