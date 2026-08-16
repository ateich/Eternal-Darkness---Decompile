typedef struct Vec3 {
    float x, y, z;
} Vec3;

extern void *fn_80200C38(void *);
extern void *fn_8004914C(void);
extern void fn_801A7744(Vec3 *, void *);
extern int fn_8011EB04(void *);
extern int fn_80047CB4(void);
extern void *fn_8015C910(void);
extern void fn_801AC9F4(int, int, Vec3 *, int);

int fn_800E1B40(void *unused, void *object)
{
    int result = 0;
    void *resource = fn_80200C38(object);
    void *current = fn_8004914C();
    Vec3 position;

    fn_801A7744(&position, resource);
    if (current != 0) {
        int type = fn_8011EB04(current);
        if (type == fn_80047CB4()) {
            if (fn_8015C910() == 0) {
                result = 1;
            }
        } else {
            fn_801AC9F4(0x2B6, 100, &position, 2);
        }
    } else {
        fn_801AC9F4(0x1C9, 100, &position, 2);
    }
    return result;
}
