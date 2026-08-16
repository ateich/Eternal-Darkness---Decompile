typedef unsigned char u8;
typedef unsigned int u32;

extern void *fn_80201B8C(void *);
extern int fn_80200C38(void *);
extern int fn_801261F4(void *);
extern int fn_8011FCEC(void *);
extern void fn_8011EBFC(void *);
extern int fn_80128EAC(void *);
extern int fn_80128F40(void *);
extern int fn_800CA13C(u8);
extern u32 fn_80036D5C(void *);
extern void fn_80036DA4(void *, u32);

#pragma use_lmw_stmw on

int fn_800CA1BC(void *object, void *other, void *component, int *result)
{
    void *info = fn_80201B8C(object);
    int active = fn_80200C38(component);
    int kind;
    int value;
    int threshold;

    if (fn_801261F4(other) != 0 && fn_8011FCEC(other) != -1) {
        fn_8011EBFC(other);
    }

    kind = fn_80128EAC(other);
    value = fn_80128F40(other) >> 17;
    threshold = fn_800CA13C(((u8 *)info)[0x9F]);
    if (kind == 0x18 && value < threshold) {
        if (result != 0) {
            *result = 0;
        }
        return 0;
    }

    if ((fn_80036D5C(object) & 0x4000) == 0) {
        if (active != 0) {
            fn_80036DA4(object, fn_80036D5C(object) | 0x4000);
            if (result != 0) {
                *result = 1;
            }
        } else if (result != 0) {
            *result = 1;
        }
    }
    return 0;
}
