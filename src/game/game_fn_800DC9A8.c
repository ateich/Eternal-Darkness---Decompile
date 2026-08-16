typedef unsigned int u32;

extern void *fn_80201B9C(void *);
extern void *fn_80201BC8();
extern float *fn_8011F130(void *);
extern int fn_80204844(void *, int);
extern int fn_8006D444(void);
extern int fn_8006D344(int, int);
extern void *fn_80204A8C(void);
extern int fn_80204D98(void);
extern int fn_8011FB4C(void *);
extern unsigned short fn_8011F760(void *);
extern void *fn_802051A4(void *);
extern void *fn_80205134(void *);
extern void *fn_80201814();
extern void *fn_80201B8C();
extern void *fn_80201C24(void *);
extern u32 fn_80179064(int, int, int, int);
extern u32 fn_80157894(void *);
extern int fn_801E1E38(void);
extern int fn_8012FF34(void *, float *, int, int);
extern void fn_801302BC(void *, int);

int fn_800DC9A8(void *context)
{
    int result = 0;
    void *owner;
    float *origin;
    void *item;
    int count;
    int kind;
    int i;

    fn_80201B9C(context);
    owner = fn_80201BC8(context);
    origin = fn_8011F130(owner);
    fn_8006D344(fn_8006D444(), 0x20200);
    if (!fn_8006D344(0, 0x20200)) {
        item = fn_80204A8C();
        count = fn_80204D98();
        kind = fn_8011FB4C(owner);
        for (i = 0; i < count; i++) {
            float *position;
            void *candidate;
            item = fn_802051A4(item);
            fn_80205134(item);
            candidate = fn_80201814(item);
            if (*((unsigned char *)fn_80201B8C(candidate) + 0x9f) == 20)
                continue;
            if (fn_8011FB4C(fn_80201BC8(candidate)) != kind)
                continue;
            position = fn_8011F130(fn_80201BC8(candidate));
            if (fn_80179064((int)origin[0], (int)position[0],
                            (int)origin[1], (int)position[1]) <= 250 &&
                !(fn_80157894(fn_80201C24(candidate)) & 8) &&
                (!(fn_80157894(fn_80201C24(candidate)) & 0x10) || fn_801E1E38()) &&
                fn_8012FF34(owner, position, 4, 2)) {
                fn_801302BC(owner, 60);
                result = 1;
            }
        }
    }
    return result;
}
