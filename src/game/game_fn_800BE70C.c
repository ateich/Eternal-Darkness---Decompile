typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern const float lbl_8064F110;
extern const float lbl_8064F114;
extern float fn_8012B7D0(void *, Vec3 *);
extern double fn_8012B750(void *);
extern void fn_8017A12C(float *, float, float);
extern void fn_8017A010(float *, float, float, float, int);
extern void fn_8012B7A0(void *, float);
extern void fn_801294DC(void *, int, int, int);

int fn_800BE70C(void *object, Vec3 *position, int type, float *delta_out,
                float turn_speed, float first_limit, float second_limit)
{
    Vec3 target = *position;
    int result = 0;
    float target_angle = fn_8012B7D0(object, &target);
    float object_angle = fn_8012B750(object);
    float delta;

    fn_8017A12C(&delta, object_angle, target_angle);
    if (delta_out != 0) {
        *delta_out = delta;
    }
    if ((delta < lbl_8064F110 ? -delta : delta) > first_limit) {
        fn_8017A010(&object_angle, target_angle, turn_speed,
                    lbl_8064F114, 0);
        fn_8012B7A0(object, object_angle);
        if ((delta < lbl_8064F110 ? -delta : delta) > second_limit) {
            fn_801294DC(object, type, 0x25, 1);
            result = 1;
        }
    }
    return result;
}

/*
 * Honest-C boundary: this reconstruction is size-exact at 352 bytes with all
 * relocations equal. Retail schedules stfs/fmr before frsp/addi around the
 * fn_8017A12C call; canonical GC/1.3 schedules the same four argument-setup
 * instructions later. The remaining code and stack/register allocation match.
 */
