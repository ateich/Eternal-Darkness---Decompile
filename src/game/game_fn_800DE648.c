typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern void *fn_80201BC8(void *);
extern Vec3 fn_80201E78(void *);
extern float fn_8012B7D0(void *, Vec3 *);
extern void fn_8012B7A0(void *);

void fn_800DE648(void *first, Vec3 *target, void *object)
{
    void *info = fn_80201BC8(object);
    Vec3 returned = fn_80201E78(object);
    {
        Vec3 position = returned;

        fn_8012B7D0(first, &position);
        fn_8012B7A0(first);
        {
            Vec3 copy = *target;
            fn_8012B7D0(info, &copy);
            fn_8012B7A0(info);
        }
    }
}
