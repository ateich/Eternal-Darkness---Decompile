extern void *fn_80201BC8();
extern void fn_800A2D78(void *);
extern void fn_800A2598(void *);
extern void fn_8012B344(void *);

void fn_800D40A8(void *state, void *object)
{
    void *saved = state;
    void *actor = fn_80201BC8(object);
    fn_800A2D78(saved);
    fn_800A2598(saved);
    fn_8012B344(actor);
}
