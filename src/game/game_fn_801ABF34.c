typedef unsigned char u8;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern void* lbl_8064C4E4;
extern float lbl_80650E6C;

extern void fn_801F68B0(Vec3*);
extern void fn_8011F114(Vec3*, void*);
extern u8 fn_801ABD3C(Vec3*, Vec3*, float, u8, u8, int);

u8 fn_801ABF34(Vec3* position, float range, u8 low, u8 high, int mode)
{
    Vec3 first_copy;
    Vec3 second_copy;
    Vec3 first;
    Vec3 second;
    u8 result;
    u8 other;

    result = 0;
    fn_801F68B0(&first);
    first_copy = first;
    if (lbl_8064C4E4 != 0) {
        fn_8011F114(&second, lbl_8064C4E4);
        second_copy = second;
        second_copy.z += lbl_80650E6C;
        result = fn_801ABD3C(position, &second_copy, range, low, high, mode);
    }
    other = fn_801ABD3C(position, &first_copy, range, low, high, mode);
    return other > result ? other : result;
}
