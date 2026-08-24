typedef int s32;

extern const char lbl_8023BEF8[];
extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_8011FF30(s32);

s32 fn_8000BF4C(void* script)
{
    s32 value = (s32)fn_8016A694(script, 1);

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    if (value != 0) {
        fn_8011FF30(value);
    } else {
        fn_8011FF30(value);
    }
    return 0;
}
