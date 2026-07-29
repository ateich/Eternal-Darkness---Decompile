typedef signed short s16;
typedef int s32;
typedef unsigned int u32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern const char lbl_8023BEF8[];
extern const double lbl_8064DCE8;

extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern s16* fn_8016A784(void*, s32);
extern void fn_8016A830(void*, double);
extern void fn_80163BB4(void*, const char*, s32, ...);
extern u32 fn_800F5C54(double);
extern void* fn_80201814(s32);
extern s32 fn_80201B54(void);
extern void fn_800CCF60(void*, s32, s32, s32, s32, s32, Vec3*, s32, s32, s32,
                       s32);

s32 fn_800176F0(void* script)
{
    u32 handle;
    s32 second;
    s32 third;
    s16* packed_position;
    Vec3 position;

    if (fn_8016A598(script) != 4) {
        fn_80163BB4(script, lbl_8023BEF8, 4, fn_8016A598(script));
        return 0;
    }

    handle = fn_800F5C54(fn_8016A694(script, 1));
    second = (s32)fn_8016A694(script, 2);
    third = (s32)fn_8016A694(script, 3);
    packed_position = fn_8016A784(script, 4);

    position.x = packed_position[0];
    position.y = packed_position[1];
    position.z = packed_position[2];

    fn_800CCF60(fn_80201814(handle), second, third, 0, -1, -1, &position, 0, 10,
                20, 0);
    fn_8016A830(script, (double)fn_80201B54());
    return 1;
}
