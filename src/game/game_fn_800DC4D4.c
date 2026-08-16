typedef unsigned int u32;

extern void *fn_80201B9C();
extern void *fn_80201B94(void *);
extern void *fn_80201BC8();
extern float *fn_8011F130(void *);
extern int fn_80204844(void *, int);
extern int fn_8006D444(void);
extern int fn_8006D344(int, int);
extern void *fn_80204A8C(void);
extern int fn_80204D98(void);
extern int fn_8011FB4C(void *);
extern void *fn_802051A4(void *);
extern void *fn_80205134(void *);
extern void *fn_80201814();
extern int fn_80201B5C(void *);
extern int fn_80201B64(void *);
extern void *fn_80201C24(void *);
extern u32 fn_80179064(int, int, int, int);
extern u32 fn_80157894(void *);
extern void fn_80201E68(void *, int);

int fn_800DC4D4(void *context)
{
    void *cursor = fn_80201B9C(context);
    void *list = fn_80201B94(context);
    void *owner = fn_80201BC8(context);
    float *origin = fn_8011F130(owner);
    int result = 0;
    int count;
    int i;

    fn_8006D344(fn_8006D444(), 0x20200);
    if (!fn_8006D344(0, 0x20200)) {
        cursor = fn_80204A8C();
        count = fn_80204D98();
        for (i = 0; i < count; i++) {
            float *position;
            void *candidate;
            cursor = fn_802051A4(cursor);
            list = fn_80205134(cursor);
            candidate = fn_80201814(list);
            if (fn_80201B5C(candidate) != 30)
                continue;
            if (fn_8011FB4C(fn_80201BC8(candidate)) != fn_8011FB4C(owner))
                continue;
            if (fn_80201B64(candidate) == 36)
                continue;
            position = fn_8011F130(fn_80201BC8(candidate));
            if (fn_80179064((int)origin[0], (int)position[0],
                            (int)origin[1], (int)position[1]) <= 250 &&
                !(fn_80157894(fn_80201C24(candidate)) & 8)) {
                fn_80201E68(list, (int)fn_80205134(cursor));
                result = 1;
                break;
            }
        }
    }
    if (!result)
        fn_80201E68(list, -1);
    return result;
}
