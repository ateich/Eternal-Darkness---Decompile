extern void *fn_80201BC8(void *);
extern int fn_80201B54(void *);
extern void *fn_801294DC(void *, int, int, int);
extern void fn_80128C44(void *, void *, int);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
extern void fn_80204810(void);

int fn_800D0AA8(void *object, int alternate)
{
    int kind = 68;
    void *resource;
    int id;
    int result;
    void *created;

    if (alternate != 0) {
        kind = 147;
    }
    resource = fn_80201BC8(object);
    id = fn_80201B54(object);
    result = 0;
    created = fn_801294DC(resource, kind, 33, 2);
    if (created != 0) {
        fn_80128C44(created, fn_80204810, (id << 8) | 7);
        if (alternate != 0) {
            fn_80201D2C(object, 120);
            fn_80201D14(object, 1);
        } else {
            fn_80201D2C(object, 115);
            fn_80201D14(object, 1);
        }
        result = 1;
    }
    return result;
}
