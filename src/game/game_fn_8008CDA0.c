/*
 * Honest C reconstruction of the next frontier routine. This remains
 * NonMatching while its call signatures and local-register order are tuned.
 */
typedef signed short s16;

extern void* fn_801A717C(void*);
extern int fn_80201B44(void);
extern void* fn_80201BC8(void*);
extern void* fn_80201B54(void*);
extern void* fn_80200C20(void*);
extern void* fn_80201814(void);
extern int fn_80036E50(void);
extern int fn_80090204(void*);
extern void fn_800389E0(void*, int, int, int);
extern void fn_801A74A0(void*, void*);
extern void fn_801A74A8(void*, int);
extern void fn_801A7538(void*, int);
extern void fn_801A7518(void*, int);
extern void fn_8020123C(int, void*, int, void*);
extern void fn_8012B344(void*);
extern void fn_80201D2C(void*, int);
extern void fn_80201D14(void*, int);
extern void fn_801A7228(void*);
extern int lbl_8064C578;

void fn_8008CDA0(void* object, void* source)
{
    void* effect;
    void* runtime;
    void* target;
    s16 amount;
    int value;

    effect = fn_801A717C(object);
    value = fn_80201B44();
    runtime = fn_80201BC8(object);
    target = fn_80201B54(object);

    fn_80200C20(source);
    if (!fn_80201814() || fn_80036E50() != 6) {
        if (!fn_80090204(object)) {
            fn_800389E0(object, 0, 1, 0);
        } else {
            switch (lbl_8064C578) {
            case 0: amount = -50; break;
            case 1: amount = -75; break;
            case 2: amount = -100; break;
            }
            fn_801A74A0(effect, target);
            fn_801A74A8(effect, value);
            fn_801A7538(effect, 2);
            fn_801A7518(effect, amount);
            fn_8020123C(39, target, value, effect);
            fn_8012B344(runtime);
            fn_80201D2C(object, 102);
            fn_80201D14(object, 1);
        }
    }
    fn_801A7228(effect);
}
