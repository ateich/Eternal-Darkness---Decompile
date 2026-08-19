extern void *fn_80201BC8();
extern void fn_801291F0(void *, int, unsigned char);
extern void *fn_801294DC(void *, int, int, int);
extern void fn_80128C28();
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
extern void fn_800E8720(void);

int fn_800E8384(void *unused, void *object)
{
    void *state = fn_80201BC8(object);
    void *created;

    fn_801291F0(state, 16, 2);
    created = fn_801294DC(state, 16, 36, 1);
    fn_80128C28(created, fn_800E8720, object);
    fn_80201D2C(object, 16);
    fn_80201D14(object, 1);
    return 0;
}
