extern void *fn_80201BC8();
extern void fn_800A30B8(void *, int);

void fn_800D406C(void *state, void *object)
{
    void *saved = state;
    fn_80201BC8(object);
    fn_800A30B8(saved, 1);
}
