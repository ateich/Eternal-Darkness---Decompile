typedef signed short s16;
typedef int s32;

#pragma use_lmw_stmw on

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

extern const char lbl_8023BEF8[];
extern const double lbl_8064DCE8;
extern s32 fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern double fn_8016A694(void*, int);
extern void* fn_8016A784(void*, int);
extern void fn_8016A830(void*, double);
extern void fn_8016A7D8(void*);
extern s32 fn_801D3C5C(s32);
extern void fn_80179DB0(Vec3*, Vec3s*);
extern s32 fn_801DD9D4(s32, s32, Vec3*, float, s32, s32, s32, s32, s32, s32*);

s32 fn_8000FDE8(void* script)
{
    register void* info = script;
    s32 count;
    s32 type;
    Vec3s* position;
    s32 fourth;
    s32 fifth;
    float scale;
    s32 seventh;
    s32 eighth;
    s32 ninth;
    s32 flags;
    Vec3 vector;
    s32 result;

    if (fn_8016A598(info) != 9) {
        fn_80163BB4(info, lbl_8023BEF8, 9, fn_8016A598(info));
        return 0;
    }

    count = (s32)fn_8016A694(info, 1);
    type = (s32)fn_8016A694(info, 2);
    position = fn_8016A784(info, 3);
    fourth = (s32)fn_8016A694(info, 4);
    fifth = (s32)fn_8016A694(info, 5);
    scale = (float)fn_8016A694(info, 6);
    seventh = (s32)fn_8016A694(info, 7);
    eighth = (s32)fn_8016A694(info, 8);
    ninth = (s32)fn_8016A694(info, 9);

    switch (count) {
    case 3:
        flags = 0x20000;
        break;
    case 4:
        flags = 0x40000;
        break;
    default:
        flags = 0x10000;
        break;
    }
    flags |= fn_801D3C5C(type);
    fn_80179DB0(&vector, position);
    if (fn_801DD9D4(flags, count, &vector, scale, fifth, fourth, seventh, eighth, ninth, &result) != 0) {
        fn_8016A830(info, (double)result);
    } else {
        fn_8016A7D8(info);
    }
    return 1;
}
