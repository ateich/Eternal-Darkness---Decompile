typedef signed short s16;

typedef struct RuntimeData {
    unsigned char pad0[80];
    void* fallback;
    unsigned char pad54[56];
    void* transform;
} RuntimeData;

extern RuntimeData* fn_80201B8C();
extern void* fn_80201B94(void*);
extern void* fn_80201B54();
extern int fn_80201B44();
extern void* fn_80201814();
extern void *fn_8011F114();
extern int fn_800CB098(int, int, int, void*, int, int);
extern void fn_80038308(void*, int, s16*);
extern void fn_80038464(void*, int, s16*);
extern int fn_8008D9F4(void*, void*, void*, int);
extern void fn_800073D8(void*);
extern void fn_80201DD8(void*, int);
extern void fn_80201D2C();
extern void fn_80201D14();
extern int fn_80036E50(void*);
extern void* lbl_8064A80C;

/*
 * NonMatching: honest control-flow reconstruction of the large interaction
 * selector. The ratio thresholds and the three primary selection paths are
 * represented; the final camera/vector fallback still needs structure and
 * floating-constant recovery before this can be considered behavior-complete.
 */
int fn_8008CEF0(void* object, void* position, void* context)
{
    RuntimeData* data = fn_80201B8C(object);
    void* runtime = fn_80201B94(object);
    void* target = fn_80201B54(object);
    int value = fn_80201B44();
    void* mode = fn_80201814();
    s16 numerator;
    s16 denominator;
    int selected = 0;
    int result = 1;
    int low;
    int high;
    float ratio;

    fn_8011F114(&ratio, position);
    low = fn_800CB098(2, 10, -1, lbl_8064A80C, 1, 0);
    high = fn_800CB098(2, 24, -1, lbl_8064A80C, 1, 0);
    fn_80038308(object, 0, &numerator);
    fn_80038464(object, 0, &denominator);
    ratio = (float)numerator / (float)denominator;

    if (*(s16*)((unsigned char*)data->fallback + 30) == 0) {
        if (ratio > 0.75f && low != 0) {
            selected = fn_8008D9F4(object, position, context, 1);
            if (selected == 0) {
                fn_800073D8(lbl_8064A80C);
                return 0;
            }
        } else if (ratio < -0.75f && (low != 0 || high != 0)) {
            selected = fn_8008D9F4(object, position, context, 1);
            high = fn_8008D9F4(object, position, context, 2);
            if (selected == 0 && high == 0) {
                result = 1;
            } else if (high != 0) {
                selected = high;
            }
        } else if ((low != 0 || high != 0) && fn_80036E50(mode) == 6) {
            selected = fn_8008D9F4(object, position, context, 1);
            high = fn_8008D9F4(object, position, context, 2);
            if (selected == 0 && high == 0)
                selected = 0;
            else if (high != 0)
                selected = high;
        }
        if (selected != 0) {
            fn_80201DD8(runtime, selected);
            fn_80201D2C(object, 3);
            fn_80201D14(object, 1);
            result = 0;
        }
    }

    if (result != 0 && fn_80036E50(mode) != 6) {
        fn_80201DD8(runtime, value);
        fn_80201D2C(object, 3);
        fn_80201D14(object, 1);
        result = 0;
    }
    (void)target;
    return result;
}
