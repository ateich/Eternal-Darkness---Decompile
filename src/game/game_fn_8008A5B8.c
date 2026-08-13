typedef unsigned char u8;
typedef signed int s32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern void* lbl_8064C4E4;
extern u8 lbl_802FC5BC[];
extern float lbl_8064EBBC;

extern s32 fn_8006D548(s32, void*, s32, Vec3*, s32*, s32, s32);
extern void fn_8011F114(Vec3*, void*);
extern s32 fn_80179064(s32, s32, s32, s32);
extern void fn_800EBA80(s32, Vec3*, void*, s32, float);

/* NonMatching: honest reconstruction of the bounded spatial-query loop. */
void fn_8008A5B8(void* object)
{
    s32 index = 0;
    s32 done = 0;

    while (done == 0) {
        Vec3 found;
        s32 query = 0;
        Vec3 current;
        s32 dx;
        s32 dz;
        s32 fx;
        s32 fz;

        done = 1;
        index = fn_8006D548(2, object, 3, &found, &query, 0, index);
        if (index == -1)
            break;

        if (lbl_8064C4E4 != 0) {
            fn_8011F114(&current, lbl_8064C4E4);
            dx = (s32)found.x;
            dz = (s32)found.y;
            fx = (s32)current.x;
            fz = (s32)current.y;
            if (__builtin_abs(fn_80179064(dx, dz, fx, fz)) < 500)
                fn_800EBA80(2, &found, lbl_802FC5BC + 0x14, 0x40,
                            lbl_8064EBBC);
        }
        done = 0;
        index++;
    }
}
