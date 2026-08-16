typedef struct Vec3_80094DD0 {
    float x, y, z;
} Vec3_80094DD0;

extern int fn_80201B44();
extern void *fn_80201814();
extern void *fn_80201B8C();
extern int fn_80036D5C(void*);
extern int fn_80201B5C(void*);
extern int fn_80201B54();
extern void fn_8011F114();
extern int fn_801E2004(void*);
extern int fn_8011F760(void*);
extern int fn_80201EB8();
extern int fn_80095D10(void*);
extern int fn_80095E64(void*, int);
extern unsigned char fn_80204508(void*, void*);
extern int fn_800C17EC(void*, void*, Vec3_80094DD0*, int, int);
extern unsigned long long fn_8020123C();

int fn_80094DD0(register void* object, register void* resource, void* unused)
{
    register void* other;
    register void* state;
    register void* component;
    register int flags;
    register int target;
    register int id;
    register int value;
    register int special;
    Vec3_80094DD0 position;

    component = ((void*)fn_80201B44(object));
    other = fn_80201814();
    state = fn_80201B8C(object);
    flags = fn_80036D5C(object);
    fn_80201B5C(object);
    state = ((void*)fn_80201B54(object));
    fn_8011F114(&position, resource);

    if ((flags & 0x80) != 0 || (flags & 0x200000) != 0) {
        return 0;
    }
    if (fn_801E2004(component) != 4) {
        id = fn_8011F760(resource);
        value = fn_80201EB8(object);
        special = fn_80201B5C(object) == 0x40;
        target = fn_80095D10(object);
        flags = fn_80095E64(object, target);
        if (target != 0 && flags != 0 && fn_80204508(other, object) != 0 &&
            (special != 0 || fn_80204508(object, other) != 0) &&
            fn_800C17EC(other, object, &position, value, id) != 0) {
            fn_8020123C(0x93, state, component, 0);
        }
    }
    return 1;
}
