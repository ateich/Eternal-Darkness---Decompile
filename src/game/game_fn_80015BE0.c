typedef int s32;
typedef signed short s16;

typedef struct Vec3f {
    float x;
    float y;
    float z;
} Vec3f;

typedef struct Value {
    s32 word;
} Value;

extern const char lbl_8023BEF8[];
extern const char lbl_8023CB0C[];
extern Value lbl_8064DE58;
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern s16* fn_8016A784(void*, s32);
extern void fn_80163BB4(void*, const char*, s32, ...);
extern void fn_80152404(Vec3f*, s32, s32, s32, Value*);

s32 fn_80015BE0(void* script)
{
    s16* position;
    s32 second;
    s32 third;
    Vec3f vector;
    Value value = lbl_8064DE58;
    Value copy;

    if (fn_8016A598(script) != 3) {
        fn_80163BB4(script, lbl_8023BEF8, 3, fn_8016A598(script));
        return 0;
    }

    position = fn_8016A784(script, 1);
    second = (s32)fn_8016A694(script, 2);
    third = (s32)fn_8016A694(script, 3);

    if (position == 0) {
        fn_80163BB4(script, lbl_8023CB0C, 0);
    }

    vector.x = position[0];
    vector.y = position[1];
    vector.z = position[2];
    copy = value;
    fn_80152404(&vector, second, third, 4, &copy);
    return 0;
}
