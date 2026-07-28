typedef int s32;

typedef struct GlobalState {
    char pad[8];
    float value;
} GlobalState;

extern const char lbl_8023BEF8[];
extern GlobalState lbl_80302060;
extern const float lbl_8064DD00;
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201814(s32);
extern void* fn_80201BC8(void*);
extern void fn_8011F0E8(void*);

s32 fn_8000D218(void* script)
{
    void* object;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    object = fn_80201814((s32)fn_8016A694(script, 1));
    object = fn_80201BC8(object);
    lbl_80302060.value += lbl_8064DD00;
    fn_8011F0E8(object);
    return 0;
}
