extern void *fn_80201C24(void *);
extern void *fn_80201BC8();
extern void fn_80157B3C(void *, int);
extern void fn_80157B60(void *, int);
extern void fn_80157930(void *, int);
extern void fn_80120B4C(void *);
extern int fn_80201AE4(void);
extern int fn_80201B54();
extern int fn_801586FC(int, int);
extern int fn_80200C38();
extern int fn_801FE25C(void *);
extern void fn_801FE024(void *, int);
extern void fn_801FDFEC(void *, int);

void fn_800DBB24(void *context, void *value)
{
    void *state = fn_80201C24(context);
    void *object = fn_80201BC8(context);

    fn_80157B3C(state, 1);
    fn_80157B60(state, 0);
    fn_80157930(state, 0);
    fn_80120B4C(object);

    {
        int id = fn_80201AE4();
        int owner = fn_80201B54(context);
        if (fn_801586FC(owner, id) != 0) {
        void **handle = (void **)fn_80200C38(value);
        if (handle != 0 && fn_801FE25C(*handle) != 0) {
            fn_801FE024(*handle, 1);
            fn_801FDFEC(*handle, 2);
        }
        }
    }
}
