typedef signed int s32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern unsigned int fn_800FBFB0();
#define fn_800FBFB0() ((int)fn_800FBFB0())
extern void fn_80211AAC(Vec3 *out, const Vec3 *in);
extern void fn_80211A90(Vec3 *out, const Vec3 *in, float scale);
extern void fn_80205868(void *object, s32 kind, const Vec3 *direction, s32 flags);

extern const float lbl_8064E700;
extern const float lbl_8064E704;
extern const double lbl_8064E708;

void fn_800685A4(void *object, s32 kind)
{
    Vec3 direction;

    direction.x = (float)(2 - (fn_800FBFB0() & 3));
    direction.y = (float)(2 - (fn_800FBFB0() & 3));
    direction.z = lbl_8064E700;
    fn_80211AAC(&direction, &direction);
    fn_80211A90(&direction, &direction, lbl_8064E704);
    fn_80205868(object, kind, &direction, 0x2000);
}
