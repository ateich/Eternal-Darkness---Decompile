extern void *fn_80201BC8(void *);
extern void fn_800A2D78(void *);
extern void fn_800A2598(void *);
extern void fn_8012B344(void *);

void fn_800CFE30(void *object, void *source)
{
    void *data = fn_80201BC8(source);
    fn_800A2D78(object);
    fn_800A2598(object);
    fn_8012B344(data);
}
