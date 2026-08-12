typedef signed int s32;
extern int fn_80201B54();
extern int fn_80200C38();
extern void fn_80201D34(void *, s32);
extern void fn_80201D1C(void *, s32);

void fn_8005BC64(void *context, void *event)
{
    void *value;
    fn_80201B54(context);
    value = (void *)fn_80200C38(event);
    fn_80201D34(context, (s32)value);
    fn_80201D1C(context, 1);
}
