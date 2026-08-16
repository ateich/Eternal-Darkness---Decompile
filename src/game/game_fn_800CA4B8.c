extern int fn_80201B54();
extern int fn_800CA554(void *, unsigned int);
extern void fn_801DD71C(int, void *, void *, int, int, int, int,
                       int (*)(void *, unsigned int), unsigned int, int);

#pragma use_lmw_stmw on

void fn_800CA4B8(void *object, void *arg1, void *arg2, int arg3,
                 int arg4, int arg5, int arg6)
{
    int model = fn_80201B54(object);
    fn_801DD71C(model, arg1, arg2, arg3, arg4, arg5, arg6,
                fn_800CA554, ((unsigned int)model << 8) | 0x78, 200);
}
