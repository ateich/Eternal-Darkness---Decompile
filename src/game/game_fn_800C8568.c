typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Vec3 { float x, y, z; } Vec3;

#pragma use_lmw_stmw on

extern void *fn_80201B9C();
extern void *fn_80201BC0(void *);
extern void *fn_80201BC8();
extern int fn_80201EB8(void *);
extern int fn_80201B54();
extern int fn_80204508(void *, void *);
extern void fn_8011F114();
extern unsigned int fn_80178E94(Vec3 *, Vec3 *);
extern void fn_801A764C(void *, Vec3 *);
extern void fn_801A74A8(void *, int);
extern void fn_801A7470(void *, int);
extern unsigned long long fn_8020123C();
extern void fn_800C928C(Vec3 *, void *, u16, void *, void **);
extern Vec3 lbl_802398A8;
extern float lbl_8064F250;

int fn_800C8568(void *self, void *target, Vec3 *position, void *arg3,
                u16 radius, void *arg5, void **extra)
{
    void *candidate;
    int self_kind;
    int self_id;
    int found = 0;

    candidate = fn_80201B9C(self);
    self_kind = fn_80201EB8(self);
    self_id = fn_80201B54(self);
    fn_801A764C(target, position);

    while (candidate != 0) {
        int candidate_id;
        void *runtime;
        Vec3 fallback;
        Vec3 candidate_position;

        if (candidate != self) {
            candidate_id = fn_80201B54(candidate);
            if (fn_80201EB8(candidate) == self_kind) {
                runtime = fn_80201BC8(candidate);
                if (runtime != 0) {
                    fn_8011F114(&fallback, runtime);
                } else {
                    fallback = lbl_802398A8;
                }
                candidate_position = fallback;
                if (candidate_id == 1) {
                    ;
                }
                if (fn_80178E94(position, &candidate_position) <= radius) {
                    fn_801A74A8(target, candidate_id);
                    if ((u8)fn_80204508(candidate, self)) {
                        fn_8020123C(0x37, self_id, candidate_id, 0);
                        fn_801A7470(target, 0xB);
                    } else {
                        fn_801A7470(target, 0xC);
                    }
                    if (self_id != 0) {
                        fn_8020123C(0xF6, candidate_id, self_id, target);
                    }
                    fn_8020123C(0x27, self_id, candidate_id, target);
                    found = 1;
                }
            }
        }
        candidate = fn_80201BC0(candidate);
    }

    position->z += lbl_8064F250;
    {
        void *extra_copy = *extra;
        fn_800C928C(position, arg3, radius, arg5, &extra_copy);
    }
    return found;
}
