extern void *fn_801A7498(void *);
extern void *fn_80201814(void *);
extern void *fn_80201BC8(void *);
extern void fn_800DD314(void *, int, int, int);

int fn_800DEA88(void *unused, void *object)
{
    void *actor = fn_80201814(fn_801A7498(object));

    fn_80201BC8(actor);
    fn_800DD314(actor, 15, 25, 250);
    return 1;
}
