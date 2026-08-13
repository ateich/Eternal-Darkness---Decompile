extern int fn_80201B54(void*);
extern void* fn_801294DC(void*, int, int, int);
extern void fn_80128C28(void*, void*, int);
extern void fn_80204810(void);
extern void fn_80201D2C(void*, int);
extern void fn_80201D14(void*, int);

int fn_8008E078(void* object, void* resource, void* argument)
{
    int value = fn_80201B54(object);
    void* created = fn_801294DC(resource, 140, 32, 6);

    if (created != 0) {
        fn_80128C28(created, fn_80204810, (value << 8) | 6);
        fn_80201D2C(object, 60);
        fn_80201D14(object, 1);
        return 1;
    }
    return 0;
}
