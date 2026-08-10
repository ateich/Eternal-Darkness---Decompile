typedef int s32;
typedef unsigned int u32;
typedef signed short s16;

typedef struct Vec3f {
    float x;
    float y;
    float z;
} Vec3f;

extern const char lbl_8023BEF8[];
extern const double lbl_8064DCE8;
extern unsigned int fn_800F5C54();
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void* fn_8016A784(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_801D5BC8(Vec3f*, u32, s32, s32, s32, s32, s32, s32, s32, s32,
                       s32, s32, s32, s32, s32);

s32 fn_80015058(void* script)
{
    s16* position;
    u32 second;
    s32 third;
    s32 fourth;
    s32 fifth;
    s32 sixth;
    s32 seventh;
    s32 eighth;
    s32 ninth;
    s32 tenth;
    s32 eleventh;
    s32 twelfth;
    s32 thirteenth;
    s32 fourteenth;
    s32 fifteenth;
    Vec3f vector;

    if (fn_8016A598(script) != 15) {
        fn_80163BB4(script, lbl_8023BEF8, 15, fn_8016A598(script));
        return 0;
    }

    position = fn_8016A784(script, 1);
    second = fn_800F5C54(fn_8016A694(script, 2));
    third = (s32)fn_8016A694(script, 3);
    fourth = (s32)fn_8016A694(script, 4);
    fifth = (s32)fn_8016A694(script, 5);
    sixth = (s32)fn_8016A694(script, 6);
    seventh = (s32)fn_8016A694(script, 7);
    eighth = (s32)fn_8016A694(script, 8);
    ninth = (s32)fn_8016A694(script, 9);
    tenth = (s32)fn_8016A694(script, 10);
    eleventh = (s32)fn_8016A694(script, 11);
    twelfth = (s32)fn_8016A694(script, 12);
    thirteenth = (s32)fn_8016A694(script, 13);
    fourteenth = (s32)fn_8016A694(script, 14);
    fifteenth = (s32)fn_8016A694(script, 15);

    vector.x = position[0];
    vector.y = position[1];
    vector.z = position[2];
    fn_801D5BC8(&vector, second, third, fourth, fifth, sixth, seventh, eighth,
                ninth, tenth, eleventh, twelfth, thirteenth, fourteenth,
                fifteenth);
    return 0;
}
