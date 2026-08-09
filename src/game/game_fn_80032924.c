typedef int s32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern const float lbl_8064E138;

extern void fn_801F68B0(Vec3*);
extern void fn_8013F3C0(float (*)[4], const Vec3*, const Vec3*, float);
extern void* fn_8015C2FC(s32);
extern void* fn_8013FBE4(void*, void*, void*, s32, s32);

s32 fn_80032924(Vec3* position, s32* screen)
{
    s32 result = 0;
    Vec3 center;
    Vec3 origin;
    char hit[0x18];
    float matrix[4][4];

    if (screen[0] <= -10 || screen[0] >= 630 ||
        screen[1] <= 10 || screen[1] >= 470) {
        result = 1;
    } else {
        fn_801F68B0(&origin);
        center = origin;
        fn_8013F3C0(matrix, position, &center, lbl_8064E138);
        if (fn_8013FBE4(fn_8015C2FC(2), matrix, hit, 0, 8) != 0) {
            result = 2;
        }
    }

    return result;
}
