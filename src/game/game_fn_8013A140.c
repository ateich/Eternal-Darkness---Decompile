typedef struct Vec3 { float x, y, z; } Vec3;

extern unsigned int fn_8011FAEC(void*);
extern int lbl_8064514C;
extern void* fn_80201B9C(void);
extern void* fn_80201BC8(void*);
extern void* fn_80201BC0(void*);
extern int fn_8011FB4C(void*);
extern Vec3* fn_8011F130(void*);
extern float fn_8011F6F0(void*);
extern int fn_80137658(float, void*, Vec3*, void*, void*);
extern void fn_8011F114(Vec3*, void*);
extern void fn_8011F104(float, float, float, void*);
extern void fn_8011F0E8(void*, Vec3*);

void fn_8013A140(void* object)
{
    if ((fn_8011FAEC(object) & 0x40) && lbl_8064514C != 0) {
        void* iterator = fn_80201B9C();
        int group = fn_8011FB4C(object);
        Vec3* facing = fn_8011F130(object);
        float radius = fn_8011F6F0(object);

        while (iterator != 0) {
            void* other = fn_80201BC8(iterator);
            if (other != 0 && other != object && fn_8011FB4C(other) == group &&
                (fn_8011FAEC(other) & 0x80)) {
                unsigned char result[48];
                if (!fn_80137658(radius, object, facing, other, result)) {
                    Vec3 position;
                    fn_8011F114(&position, other);
                    position.z -= 1.0f;
                    fn_8011F104(position.x, position.y, position.z, other);
                    if (!fn_80137658(radius, object, facing, other, result))
                        fn_8011F0E8(other, &position);
                }
            }
            iterator = fn_80201BC0(iterator);
        }
    }
}
