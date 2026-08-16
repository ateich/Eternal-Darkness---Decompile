typedef unsigned char u8;
typedef unsigned int u32;

extern void fn_801A7498(void *);
extern void *fn_80201814(void);
extern void **fn_80201B8C(void);
extern void fn_802042A4(void *, void *);
extern void fn_801A74D8(void *, int);
extern int fn_800BFF84(void *, void *);
extern u32 fn_8011FAEC(void *);
extern int fn_80128F40(void *);
extern int fn_80128EAC(void *);
extern int fn_8012A1BC(void *, int);

int fn_800C0240(void *object, void *event)
{
    void *runtime;
    int value;
    int limit;
    int clamped;

    fn_801A7498(event);
    fn_80201814();
    runtime = *fn_80201B8C();
    fn_802042A4(object, event);
    fn_801A74D8(event, 0x80);
    fn_800BFF84(object, event);

    if ((fn_8011FAEC(object) & 0x400) != 0) {
        limit = fn_80128F40(object);
        value = fn_8012A1BC(object, fn_80128EAC(object));
        limit >>= 17;
        value -= limit;
        if (value > 0) {
            clamped = value < 20 ? value : 20;
            ((u8 *)runtime)[0x94] = (u8)(clamped << 1);
        }
    }
    return 1;
}
