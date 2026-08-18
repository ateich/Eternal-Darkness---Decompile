extern int lbl_8064D18C;

extern void *fn_80201B9C();
extern int fn_80201EB8();
extern void *fn_80201BC8();
extern void* fn_80201BC0(void*);
extern void fn_8011F7E0(void*, int);
extern void fn_80126880(void*);

void fn_8012BD4C(void)
{
    void* node;
    void* object;

    node = fn_80201B9C();
    while (node != 0) {
        if (fn_80201EB8(node) == lbl_8064D18C) {
            object = fn_80201BC8(node);
            if (object != 0) {
                fn_8011F7E0(object, 0);
                fn_80126880(object);
            }
        }
        node = fn_80201BC0(node);
    }
}
