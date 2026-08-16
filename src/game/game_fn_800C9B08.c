extern void fn_80201B64(void *);
extern void fn_80201B54(void *);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
extern void fn_8012B344(void *);
extern void fn_80201B6C(void *);

int fn_800C9B08(void *context, void *object, int unused)
{
    fn_80201B64(context);
    fn_80201B54(context);
    fn_80201D2C(context, 0x5F);
    fn_80201D14(context, 1);
    fn_8012B344(object);
    fn_80201B6C(context);
    return 1;
}
