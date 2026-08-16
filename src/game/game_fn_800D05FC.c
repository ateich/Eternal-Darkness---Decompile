extern int fn_801A7468(void *);
extern void fn_801287C4(void *, void *, void *, int);
extern void fn_801296E8(void *, int);
extern void fn_801A7560(void *, int);
extern void fn_800D082C(void);
extern void fn_800A3468(void);
extern void fn_800A1A24(void);
extern void fn_800A1A04(void);

void fn_800D05FC(void *object, void *unused, void *target, void *context)
{
    int index;

    fn_801A7468(context);
    for (index = 41; index < 50; index += 2) {
        fn_801287C4(target, fn_800D082C, context, index);
    }
    fn_801296E8(target, 0x20000);
    fn_801287C4(target, fn_800A3468, context, 43);
    fn_801287C4(target, fn_800A1A24, object, 15);
    fn_801287C4(target, fn_800A1A04, (void *)0x8000, 30);
    fn_801287C4(target, fn_800A1A04, (void *)0x10000, 35);
    fn_801A7560(context, 0x2000);
}
