typedef int s32;

typedef struct Vec3f {
    float x;
    float y;
    float z;
} Vec3f;

extern const char lbl_8023BEF8[];
extern const float lbl_8064DD00;
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_8016A830(void*, double);
extern void fn_80163BB4(void*, const char*, s32, s32, ...);
extern void* fn_80201814(s32);
extern void* fn_80201BC8(void*);
extern void fn_8011F114(Vec3f*, void*);
extern s32 fn_801FBC18(Vec3f*, float);

s32 fn_8000AEB4(void* script)
{
    s32 result = 0;
    void* entry;
    void* info;
    Vec3f source;
    Vec3f position;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }
    entry = fn_80201814((s32)fn_8016A694(script, 1));
    if (entry != 0) {
        info = fn_80201BC8(entry);
    } else {
        info = 0;
    }
    if (info != 0) {
        fn_8011F114(&source, info);
        position = source;
        result = fn_801FBC18(&position, lbl_8064DD00);
    }
    fn_8016A830(script, result);
    return 1;
}
