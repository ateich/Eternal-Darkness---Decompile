extern void *fn_80201BC8(void *);
extern int fn_80201B54(void *);
extern void *fn_801294DC(void *, int, int, int);
extern void fn_80128C44(void *, void *, int);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
extern void fn_80204810(void);

int fn_800D0A04(void *object)
{
    void *resource = fn_80201BC8(object);
    int id = fn_80201B54(object);
    int result = 0;
    void *created = fn_801294DC(resource, 78, 32, 6);

    if (created != 0) {
        fn_80128C44(created, fn_80204810, (id << 8) | 7);
        fn_80201D2C(object, 86);
        fn_80201D14(object, 1);
        result = 1;
    }
    return result;
}
