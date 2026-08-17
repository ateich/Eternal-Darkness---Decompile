extern void *fn_80201BC8();
extern void* fn_80201B3C();
#define fn_80201B3C(a) ((unsigned int)fn_80201B3C(a))
extern void *fn_80201C2C(void);
extern unsigned int fn_80204A94(void *, void *);
extern int fn_80200C38();
extern void *fn_80047D78(void);
extern void *fn_80047D6C(void);
extern void fn_80047DF8(void *, void *, unsigned char);

void fn_800DBA84(void *context, void *value)
{
    void *object;
    void *active;

    object = fn_80201BC8(context);
    if (fn_80201B3C(object) != 0 && fn_80204A94(fn_80201C2C(), context) == 0) {
        if ((unsigned char)fn_80200C38(value) != 0) {
            active = fn_80047D78();
        } else {
            active = fn_80047D6C();
        }
        fn_80047DF8(object, active, (unsigned char)fn_80200C38(value));
    }
}
