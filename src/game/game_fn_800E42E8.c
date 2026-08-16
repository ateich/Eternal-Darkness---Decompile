extern int fn_80201B54(int);
extern void *fn_80201BC8(int);
extern void *fn_801294DC(void *, int, int, int);
extern void fn_801593B4(int);
extern int fn_800E44E0(void *, int, int);
extern int fn_800E4520(void *, int, int);
extern void fn_801287C4(void *, void *, int, int);
extern void fn_80128C28(void *, void *, int);
extern void fn_80204810(void);
extern void fn_80201D2C(int, int);
extern void fn_80201D14(int, int);
extern void fn_801B0CA4(int, int);
extern void fn_800E43CC(void *);

void fn_800E42E8(int id, int finish)
{
    int object;
    void *created;
    void *resource;

    object = fn_80201B54(id);
    resource = fn_80201BC8(id);
    created = fn_801294DC(resource, 25, 32, 8);
    if (created != 0) {
        fn_801593B4(323);
        fn_801593B4(213);
        fn_801287C4(created, fn_800E44E0, 0, 30);
        fn_801287C4(created, fn_800E4520, 0, 60);
        fn_80128C28(created, fn_80204810, (object << 8) | 20);
        fn_80201D2C(id, 15);
        fn_80201D14(id, 1);
    }
    fn_801B0CA4(-1, 39);
    if (finish != 0)
        fn_800E43CC(resource);
}
