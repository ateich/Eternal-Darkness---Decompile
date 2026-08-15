typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

#pragma use_lmw_stmw on

extern const Vec3 lbl_80239800;
extern const Vec3 lbl_8023980C;
extern void *fn_80201B9C(void);
extern void *fn_80201BC8(void *);
extern Vec3 *fn_8011F114(Vec3 *, void *);
extern int fn_80201EB8(void *);
extern int fn_80201B54(void *);
extern void *fn_80201BC0(void *);
extern unsigned int fn_80178E94(Vec3 *, Vec3 *);
extern void fn_8020123C(int, int, int, int);

void fn_800BEBE4(void *object, unsigned int limit)
{
    void *candidate = fn_80201B9C();
    int object_id;
    int owner;
    Vec3 object_position;
    Vec3 candidate_position;
    Vec3 object_temporary;
    Vec3 object_fallback;
    Vec3 candidate_temporary;
    Vec3 *source;
    void *position_object;

    position_object = fn_80201BC8(object);
    if (position_object != 0) {
        fn_8011F114(&object_temporary, position_object);
        source = &object_temporary;
    } else {
        object_fallback = lbl_80239800;
        source = &object_fallback;
    }
    object_position = *source;

    object_id = fn_80201EB8(object);
    owner = fn_80201B54(object);
    while (candidate != 0) {
        position_object = fn_80201BC8(candidate);
        if (position_object != 0) {
            fn_8011F114(&candidate_temporary, position_object);
            source = &candidate_temporary;
        } else {
            Vec3 fallback = lbl_8023980C;
            source = &fallback;
        }
        candidate_position = *source;

        if (object_id == fn_80201EB8(candidate) &&
            fn_80178E94(&object_position, &candidate_position) < limit &&
            object != candidate) {
            fn_8020123C(13, owner, fn_80201B54(candidate), 0);
        }
        candidate = fn_80201BC0(candidate);
    }
}
