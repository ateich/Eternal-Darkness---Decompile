extern void *fn_80201C24(void *);
extern void *fn_80157900(void *);
extern int fn_80201B54();
extern void fn_8016B400(void *, int, int);

void fn_800DB9B0(void *context)
{
    void *target = fn_80157900(fn_80201C24(context));

    if (target != 0) {
        int owner = fn_80201B54(context);
        fn_8016B400(target, 0, owner);
    }
}
