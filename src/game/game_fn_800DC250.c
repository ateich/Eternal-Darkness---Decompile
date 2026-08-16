extern float fn_800DC398(void *);
extern void fn_800DBF60(void *, void *, void *, void *, float);

void fn_800DC250(void *owner, void *object, void *kind, void *effect)
{
    float amount = fn_800DC398(kind);
    fn_800DBF60(owner, object, kind, effect, amount);
}
