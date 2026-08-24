typedef int s32;

extern const char lbl_8023BEF8[];

extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern void *fn_80201BC8();
extern void fn_8011FA8C(void*, int, int);

s32 fn_8001A2A4(void* script)
{
    s32 first;
    s32 second;
    void* object;

    if (fn_8016A598(script) != 2) {
        fn_80163BB4(script, lbl_8023BEF8, 2, fn_8016A598(script));
        return 0;
    }

    first = (s32)fn_8016A694(script, 1);
    second = (s32)fn_8016A694(script, 2);
    if (fn_80201814(first) != 0 && (object = fn_80201BC8()) != 0) {
        if (second != 0) {
            fn_8011FA8C(object, 0, 0x04000000);
        } else {
            fn_8011FA8C(object, 0x04000000, 0);
        }
    }
    return 0;
}
