typedef unsigned char u8;

typedef struct Vec8012AC74 {
    float x;
    float y;
    float z;
} Vec8012AC74;

extern int fn_8011EB1C(void*);
extern int fn_8011EB04(void*);
extern void* fn_8011F770(void*);
extern void fn_80211A48(const Vec8012AC74*, const void*, Vec8012AC74*);
extern void fn_80211A6C(const Vec8012AC74*, const void*, Vec8012AC74*);
extern void fn_80139F28(void*, const Vec8012AC74*, const Vec8012AC74*,
                       Vec8012AC74*, int);
extern void fn_8013A140(void*);

void fn_8012AC74(void* owner, const Vec8012AC74* value, int flags)
{
    int mode;
    int type;
    void* transform;
    Vec8012AC74 current;
    Vec8012AC74 target;
    Vec8012AC74 result;

    mode = fn_8011EB1C(owner);
    type = fn_8011EB04(owner);
    if (mode == 3 &&
        (type == 1 || type == 2 || type == 3 || type == 0x57)) {
        *(Vec8012AC74*)owner = *value;
        fn_8013A140(owner);
    } else {
        transform = fn_8011F770(owner);
        fn_80211A48((Vec8012AC74*)owner, transform, &current);
        fn_80211A48(value, transform, &target);
        fn_80139F28(owner, &current, &target, &result, flags);
        fn_80211A6C(&result, transform, (Vec8012AC74*)owner);
    }
}
