typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct Segment {
    Vec3 first;
    Vec3 second;
    Vec3 axis;
    float length;
} Segment;

extern void *fn_8015C2FC(int selector);
extern void fn_8013F4D0(Segment *out, const Vec3 *first, const Vec3 *second);
extern void *fn_80140258(void *owner, const Vec3 *value, Vec3 *out, int flags, void *filter);

int fn_800EAF7C(const Vec3 *first, const Vec3 *second, int height)
{
    Segment segment;
    Vec3 hit;
    Vec3 raisedFirst;
    Vec3 raisedSecond;
    void *owner;
    int result = 0;

    raisedFirst = *first;
    raisedFirst.z += height;
    raisedSecond = *second;
    raisedSecond.z += height;
    owner = fn_8015C2FC(2);
    fn_8013F4D0(&segment, &raisedFirst, &raisedSecond);
    if (fn_80140258(owner, (Vec3 *)&segment, &hit, 0x1D, 0) != 0) {
        result = 1;
    }
    return result;
}
