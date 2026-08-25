typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3s {
    short x;
    short y;
    short z;
} Vec3s;

typedef struct Vec3f {
    float x;
    float y;
    float z;
} Vec3f;

typedef struct Color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Color;

extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_80179904(void*, short);
extern void fn_80153F00(u8, u8, u8, u8, Color*, int, Vec3f*, void*, u8, u8,
                       int);
extern const char lbl_8024FF00[];

int fn_801734B4(void* state)
{
    int arg1, arg2, arg3;
    int arg13;
    int arg16;
    int arg7;
    int arg8;
    int arg9;
    int arg10;
    int arg11;
    int arg12;
    int arg14;
    int arg15;
    int arg17;
    Color color;
    Vec3s resource;
    Vec3f position;

    if (fn_8016A598(state) != 17) {
        fn_80163BB4(state, lbl_8024FF00, 17, fn_8016A598(state));
        return 0;
    }

    arg1 = fn_8016A694(state, 1);
    arg2 = fn_8016A694(state, 2);
    arg3 = fn_8016A694(state, 3);
    resource.x = fn_8016A694(state, 4);
    resource.y = fn_8016A694(state, 5);
    resource.z = fn_8016A694(state, 6);
    arg7 = fn_8016A694(state, 7);
    arg8 = fn_8016A694(state, 8);
    arg9 = fn_8016A694(state, 9);
    arg10 = fn_8016A694(state, 10);
    arg11 = fn_8016A694(state, 11);
    arg12 = fn_8016A694(state, 12);
    arg13 = fn_8016A694(state, 13);
    arg14 = fn_8016A694(state, 14);
    arg15 = fn_8016A694(state, 15);
    arg16 = fn_8016A694(state, 16);
    arg17 = fn_8016A694(state, 17);

    arg15 += (u16)arg17;
    color.r = arg7;
    color.g = arg8;
    color.b = arg9;
    color.a = arg10;
    position.x = (short)arg1;
    position.y = (short)arg2;
    position.z = (short)arg3;
    fn_80179904(&resource, arg16);
    fn_80153F00((u8)arg13, (u8)arg12, (u8)arg14, (u8)arg11, &color,
                arg15, &position, &resource, 1, 1, arg17);
    return 0;
}
