extern void* fn_801294DC(void*, int, int, int);
extern void fn_80204810(void);
extern void fn_80128C28(void*, void*, int);
extern void fn_80128C44(void*, void*, int);
extern void fn_800DD314(void*, int, int, int);
extern void fn_80201D2C();
extern void fn_80201D14();

void fn_8008E670(void* object, int object_id, void* resource)
{
    void* created = fn_801294DC(resource, 140, 32, 6);
    if (created != 0) {
        object_id <<= 8;
        fn_80128C28(created, fn_80204810, object_id | 6);
        fn_80128C44(created, fn_80204810, object_id | 7);
        fn_800DD314(object, 15, 3, 0);
        fn_80201D2C(object, 60);
        fn_80201D14(object, 1);
    }
}
