extern void *fn_80201BC8();
extern int fn_8011F130(void *);
extern void fn_801F74C8(int, int, int);
extern void fn_801441C0(int, int, int);
extern int fn_801AC9F4(int, int, int, int);
extern void *fn_801294DC(void *, int, int, int);
extern void fn_80128C28();
extern void fn_800C78C4(void);

void fn_800C82F0(void *object)
{
    int count;
    void *runtime;
    void *effect;

    runtime = fn_80201BC8(object);
    count = fn_8011F130(runtime);

    fn_801F74C8(0xAE, 1, 5);
    fn_801441C0(1, 1, 0xAE);
    fn_801AC9F4(0x26A, 0x7F, count, 2);
    effect = fn_801294DC(runtime, 4, 0x30, 6);
    fn_80128C28(effect, fn_800C78C4, object);
}
