extern void *fn_80201BC8();
extern void *fn_80201B54();
extern void fn_80201910(void *);
extern int fn_8011F130(void *);
extern void fn_801F74C8(int, int, int);
extern void fn_801441C0(int, int, int);
extern void fn_801AC9F4(int, int, int, int);
extern void *fn_801294DC(void *, int, int, int);
extern int fn_8012A1BC(void *, int);
extern void fn_801287C4(void *, void (*)(void), void *, int);
extern void fn_80128A84(void *, int, int);
extern void fn_80128C28(void *, void (*)(void), void *);
extern void fn_800C7844(void);
extern void fn_800C77FC(void);
extern void *lbl_8064C4E4;

void fn_800C81E0(void *object)
{
    void *runtime = fn_80201BC8(object);
    int count;
    void *owner;
    void *effect;

    owner = fn_80201B54(object);
    count = fn_8011F130(lbl_8064C4E4);

    fn_801F74C8(0xAE, 1, 5);
    fn_801441C0(1, 1, 0xAE);
    fn_801AC9F4(0x26A, 0x7F, count, 2);
    effect = fn_801294DC(runtime, 0x10, 0x30, 1);
    if (effect != 0) {
        int index = fn_8012A1BC(runtime, 0x10);
        fn_80201910(owner);
        fn_801287C4(effect, fn_800C7844, object, index - 2);
        fn_80128A84(effect, 0x3C, index - 1);
        fn_80128C28(effect, fn_800C77FC, object);
    }
}
