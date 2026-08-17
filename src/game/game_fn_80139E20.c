typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Matrix34 {
    float m[3][4];
} Matrix34;
typedef struct Matrix44 {
    float m[4][4];
} Matrix44;

extern int lbl_8064B7F0;
extern float lbl_806502B8;
extern float fn_8011F904(void*);
extern unsigned int fn_8011FAEC(void*);
extern void* fn_8012AB2C(void*);
extern Vec3* fn_8011F8FC(void*);
extern Matrix34* fn_8011F6F8(void*);
extern void fn_8013F3C0(Matrix34*, const Vec3*, const Vec3*);
extern void fn_8013A538(void*, void*, Matrix34*, int, void*, void*);

void fn_80139E20(void* object, Vec3* position, void* result)
{
    float scale = fn_8011F904(object);

    if (!(lbl_806502B8 == scale) && !(fn_8011FAEC(object) & 0x800) && lbl_8064B7F0 != 0) {
        Vec3* end;
        void* value = fn_8012AB2C(object);
        Vec3* direction = fn_8011F8FC(object);
        Matrix44 matrix;
        unsigned char local[24];
        end = (Vec3*)&matrix.m[0][3];

        end->x = position->x + scale * direction->x;
        end->y = position->y + scale * direction->y;
        end->z = position->z + scale * direction->z;
        fn_8011F6F8(object);
        fn_8013F3C0((Matrix34*)&matrix, position, end);
        fn_8013A538(object, value, (Matrix34*)&matrix, 1, local, result);
        *position = *end;
    }
}
