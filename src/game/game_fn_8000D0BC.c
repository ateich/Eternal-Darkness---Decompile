typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern void *fn_80201BC8();
extern int fn_8011EB04(void *);
#define fn_8011EB04(a) fn_8011EB04((void *)(a))
extern void fn_8016A830(void*, double);

s32 fn_8000D0BC(void* script)
{
    s32 result = -1;
    void* object;
    void* transform;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    object = fn_80201814((s32)fn_8016A694(script, 1));
    if (object != 0 && (transform = fn_80201BC8(object)) != 0) {
        result = fn_8011EB04(transform);
    }
    fn_8016A830(script, result);
    return 1;
}
