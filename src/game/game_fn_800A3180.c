typedef unsigned short u16;

typedef struct Vec3_800A3180 {
    float x;
    float y;
    float z;
} Vec3_800A3180;

extern void fn_80201B94(void);
extern int fn_80201C48(void);
extern void* fn_80201814();
extern u16 fn_800A30CC(void*);
extern void fn_802045AC(void*, Vec3_800A3180*);
extern void fn_80211A6C(Vec3_800A3180*, Vec3_800A3180*, Vec3_800A3180*);
extern int fn_800A4F44(Vec3_800A3180*, float);

/*
 * Behavior-complete, size-equal reconstruction. Retail assigns result/radius
 * to r31/r30, while this isolated TU assigns them to r30/r31. It also names
 * the unsigned-to-float bias relocation as lbl_8064EE78 instead of MWCC's
 * TU-local @11 constant. Objdiff: 66.041664%, 192/192 bytes.
 */
int fn_800A3180(void* object, Vec3_800A3180* target)
{
    int condition;
    u16 radius;
    int result;

    fn_80201B94();
    condition = fn_80201C48();
    result = 0;
    if (condition != 0 && fn_80201814() != 0) {
        Vec3_800A3180 position;
        Vec3_800A3180 delta;

        radius = fn_800A30CC(object);
        fn_802045AC(object, &position);
        fn_80211A6C(&position, target, &delta);
        if (fn_800A4F44(&delta, radius) <= 0) {
            result = 1;
        }
    }
    return result;
}
