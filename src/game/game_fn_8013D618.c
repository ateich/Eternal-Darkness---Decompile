typedef struct Vec3 { float x, y, z; } Vec3;

extern float fn_80211D4C(const Vec3*, const Vec3*);
extern float fn_80211B44(const Vec3*, const Vec3*);

unsigned char fn_8013D618(const Vec3* first, const Vec3* second,
                          float radius, float threshold,
                          const Vec3* direction)
{
    if (fn_80211D4C(first, second) < radius * radius) {
        return fn_80211B44(first, direction) > threshold;
    }
    return 0;
}
