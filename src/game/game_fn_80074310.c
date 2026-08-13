typedef unsigned char u8;

#pragma use_lmw_stmw on

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct State {
    u8 pad_00[0x1B4];
    void *handle;
} State;

extern int fn_80128F40(void *);
extern void fn_80211A6C(const Vec3 *, const Vec3 *, Vec3 *);
extern float fn_80211B08(const Vec3 *);
extern void fn_80211AAC(const Vec3 *, Vec3 *);
extern void fn_80211A90(const Vec3 *, Vec3 *, float);
extern void fn_80128B8C(void *, Vec3 *);
extern void *fn_80137FB8(void *);
extern float fn_800490E8(float, float);
extern void fn_8012B7A0(void *, float);
extern void fn_80128B34(void *, Vec3 *);
extern const double lbl_8064E888;
extern const float lbl_8064E87C;
extern const float lbl_8064E880;
extern const float lbl_8064E870;

int fn_80074310(void *object, Vec3 *position, State *state, Vec3 *target)
{
    Vec3 direction;
    Vec3 other_direction;
    int height;
    void *other;
    float length;

    height = fn_80128F40(object) >> 17;
    if (height < 36) {
        fn_80211A6C(target, position, &direction);
        length = fn_80211B08(&direction);
        fn_80211AAC(&direction, &direction);
        fn_80211A90(&direction, &direction, length / ((36 - height) * 2));
        fn_80128B8C(object, &direction);
        other = fn_80137FB8(state->handle);
        if (other != 0) {
            fn_80211A6C(target, other, &other_direction);
            if (fn_80211B08(&other_direction) > lbl_8064E87C) {
                fn_8012B7A0(object, lbl_8064E880 + fn_800490E8(other_direction.y, other_direction.x));
            }
        }
        return 1;
    }
    direction.x = lbl_8064E870;
    direction.y = lbl_8064E870;
    direction.z = lbl_8064E870;
    fn_80128B34(object, &direction);
    return 0;
}
