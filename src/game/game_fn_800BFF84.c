extern void *fn_8004914C(void *);
extern void *fn_801A7778(void *);
extern void fn_800BFFDC(void *, void *, int);

int fn_800BFF84(void *unused, void *event)
{
    void *object = fn_8004914C(event);
    void *state = fn_801A7778(event);
    fn_800BFFDC(object, state, 0);
    return 1;
}
