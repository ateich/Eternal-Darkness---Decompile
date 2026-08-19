typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Transform {
    float pad[4];
    float scale;
} Transform;

extern float lbl_8064F1FC;

extern void *fn_80201BC8();
extern float fn_8011F6F0(void);
extern void fn_8011F114();
extern void fn_80211A6C(void *, const Vec3 *, Vec3 *);
extern Vec3 *fn_80211AAC(Vec3 *, const Vec3 *);
extern void fn_80211A90(Vec3 *, Vec3 *, float);
extern Vec3 *fn_80211A48(Vec3 *, const Vec3 *, Vec3 *);
extern void fn_8012AC74(void *, Vec3 *, int);

void fn_800C677C(void *object, Transform *transform, int mode)
{
    Vec3 result;
    Vec3 direction;
    Vec3 scaled_transform;
    Vec3 scaled_time;
    Vec3 origin;
    void *node;
    float time;

    node = fn_80201BC8(object);
    time = fn_8011F6F0() / lbl_8064F1FC;
    fn_8011F114(&origin, node);
    fn_80211A6C(transform, &origin, &direction);
    fn_80211AAC(&direction, &direction);
    fn_80211A90(&direction, &scaled_transform, transform->scale);
    fn_80211A90(&direction, &scaled_time, time);

    switch (mode) {
    case 0:
        fn_80211A48(&origin, &scaled_transform, &result);
        fn_80211A48(&result, &scaled_time, &result);
        break;
    case 1:
        fn_80211A6C(&origin, &scaled_transform, &result);
        fn_80211A6C(&result, &scaled_time, &result);
        break;
    }
    fn_8012AC74(node, &result, 3);
}
