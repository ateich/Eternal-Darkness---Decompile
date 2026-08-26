extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern void *fn_80201BC8();
extern void fn_8011FA8C(void*, int, int);
extern const char lbl_8024FF00[];

int fn_80177034(void* state)
{
    int first;
    int second;
    void* object;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, lbl_8024FF00, 2, fn_8016A598(state));
        return 0;
    }

    first = (int)fn_8016A694(state, 1);
    second = (int)fn_8016A694(state, 2);
    object = fn_80201BC8(fn_80201814(first));
    if (second != 0) {
        fn_8011FA8C(object, 0x800, 0);
    } else {
        fn_8011FA8C(object, 0, 0x800);
    }
    return 1;
}
