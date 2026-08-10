typedef int s32;
typedef signed short s16;

typedef struct Vec3f {
    float x;
    float y;
    float z;
} Vec3f;

extern const char lbl_8023BEF8[];
extern const char lbl_8023CB0C[];
extern float lbl_8064DE5C;
extern s32 fn_8016A598(void*);
extern s16* fn_8016A784(void*, s32);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_80152838(Vec3f*, Vec3f*, s32);

s32 fn_80016128(void* script)
{
    s16* position;
    Vec3f start;
    Vec3f end;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    position = fn_8016A784(script, 1);
    if (position == 0) {
        fn_80163BB4(script, lbl_8023CB0C, 0);
    }

    start.x = position[0];
    start.y = position[1];
    start.z = position[2];
    end.x = position[0];
    end.y = position[1];
    end.z = lbl_8064DE5C + position[2];
    fn_80152838(&start, &end, 4);
    return 0;
}
