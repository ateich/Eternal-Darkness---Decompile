extern void *fn_80201BC8(void *);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);

int fn_800C7878(int unused, void *object)
{
    fn_80201BC8(object);
    fn_80201D2C(object, 14);
    fn_80201D14(object, 1);
    return 1;
}
