extern int fn_80200C10(void *);
extern int fn_80200C38(void *);
extern void *fn_80201BC8();
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
extern void fn_80201D34(void *, int);
extern void fn_80201D1C(void *, int);
extern void fn_8012B324(void);
extern void fn_801E8328(int, void *);
extern void fn_800DB9B0(void *);
extern void fn_800DB62C(void *);
extern void fn_800DBB24(void *, void *);

int fn_800DCBC0(void *context, int phase, void *message, int *handled)
{
    int kind = fn_80200C10(message);
    void *object = fn_80201BC8(context);

    if (phase == 0) {
        if (kind == 1) {
            fn_80201D2C(context, 1);
            fn_80201D14(context, 1);
            return 1;
        }
        if (kind == 240) {
            fn_80201D34(context, fn_80200C38(message));
            fn_80201D1C(context, 1);
            if (handled != 0)
                *handled = 1;
            return 1;
        }
        if (kind == 61 || kind == 62)
            return 1;
        if (kind == 57) {
            fn_8012B324();
            fn_80201D34(context, 0);
            fn_80201D1C(context, 1);
            fn_801E8328(2, context);
            return 1;
        }
        return 0;
    }
    if (phase != 1)
        return 0;
    if (kind == 190) {
        fn_800DB9B0(context);
        fn_800DB62C(context);
        return 1;
    }
    if (kind == 75) {
        fn_800DBB24(context, message);
        return 1;
    }
    if (kind != 3)
        return 0;
    (void)object;
    return 1;
}
