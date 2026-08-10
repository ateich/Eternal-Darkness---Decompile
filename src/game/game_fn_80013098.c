typedef int s32;
typedef signed short s16;

typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

extern const char lbl_8023BEF8[];
extern void* lbl_8064C4E4;
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern Vec3s* fn_8016A784(void*, s32);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_80205470(void*, s32, Vec3s*, s32, float);

s32 fn_80013098(void* script)
{
    s32 value;
    Vec3s* position;
    void* parser = script;
    float scale;

    if (fn_8016A598(parser) != 3) {
        fn_80163BB4(parser, lbl_8023BEF8, 3, fn_8016A598(parser));
        return 0;
    }

    position = fn_8016A784(parser, 1);
    value = (s32)fn_8016A694(parser, 2);
    scale = (float)fn_8016A694(parser, 3);
    fn_80205470(lbl_8064C4E4, value, position, 0x48, scale);
    return 0;
}
