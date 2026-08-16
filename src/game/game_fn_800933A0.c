typedef unsigned int u32;

extern u32 fn_80036D5C(void*);
extern int fn_80201B54();
extern int fn_80128EAC(void*);
extern void *fn_801294DC(void *, int, int, int);
extern void fn_80128C28(void*, void (*)(void), int);
extern void fn_80204810(void);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);

void fn_800933A0(register void* object, register void* event, void* unused,
                 register int* result)
{
    register int kind;

    fn_80036D5C(object);
    kind = fn_80201B54(object);
    if (fn_80128EAC(event) == 47) {
        if (result != 0)
            *result = 1;
        fn_80201D2C(object, 5);
        fn_80201D14(object, 1);
    } else {
        void* action = fn_801294DC(event, 46, 32, 6);
        if (action != 0) {
            fn_80128C28(action, fn_80204810, (kind << 8) | 0xA8);
            if (result != 0)
                *result = 1;
            fn_80201D2C(object, 5);
            fn_80201D14(object, 1);
        } else if (result != 0) {
            *result = 0;
        }
    }
}
