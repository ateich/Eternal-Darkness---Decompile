typedef struct Vec3f {
    float x, y, z;
} Vec3f;

extern int lbl_8064D5A8;
extern int fn_800E4728(void *);
extern int fn_800CB8F4(void *, int, int, Vec3f *);
extern int fn_800CB760(void *, int, int, Vec3f *);
extern int fn_8012FF34(void *, Vec3f *, int, int);
extern void fn_801302BC(void *, int);

void fn_800CB694(void *object)
{
    Vec3f first;
    Vec3f second;

    if (fn_800E4728(object) != 0) {
        if (fn_800CB8F4(object, 2, 0x800, &first) != 0 &&
            fn_8012FF34(object, &first, 4, 3) != 0) {
            fn_801302BC(object, 60);
        }
    } else if ((lbl_8064D5A8 & 0x3F) == 0) {
        if (fn_800CB760(object, 2, 0x400, &second) != 0 &&
            fn_8012FF34(object, &second, 4, 1) != 0) {
            fn_801302BC(object, 300);
        }
    }
}
