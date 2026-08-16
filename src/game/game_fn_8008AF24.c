typedef unsigned int u32;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

extern void fn_8011FAEC(void*);
extern void fn_8011F114();
extern int fn_80201B54();
extern int fn_8008C7C0(void*, int);
extern void* fn_80201B94(void*);
extern void* fn_80201C48(void*);
extern void *fn_80201814();
extern void fn_802045AC(void*, Vec3*);
extern int fn_80179064(int, int, int, int);
extern float fn_800CB444(void*, void*);
extern int fn_8012AFC4(void*);
extern void fn_8012B344(void*);
extern int fn_8008A96C(void*, void*, void*);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);

int fn_8008AF24(void* object, void* resource, void* argument, u32 flags, u32 mask)
{
    int success = 0;
    Vec3 positionCopy;
    Vec3 objectPosition;
    Vec3 position;
    void* target;
    int distance;

    fn_8011FAEC(resource);
    if ((flags & mask) == 0) {
        fn_8011F114(&position, resource);
        positionCopy = position;
        ((void*)fn_80201B54(object));
        if (fn_8008C7C0(object, 0)) {
            target = fn_80201814(fn_80201C48(fn_80201B94(object)));
            fn_802045AC(object, &objectPosition);
            distance = fn_80179064((int)positionCopy.x, (int)positionCopy.y,
                                   (int)objectPosition.x, (int)objectPosition.y);
            if (distance < (int)fn_800CB444(object, target)) {
                if (fn_8012AFC4(resource))
                    fn_8012B344(resource);
                success = fn_8008A96C(object, resource, argument);
            } else {
                fn_80201D2C(object, 3);
                fn_80201D14(object, 1);
                success = 1;
            }
        }
    }
    return success;
}
