extern int fn_80200C38(void*);
extern void *fn_801294DC(void *, int, int, int);
extern void fn_80128C44(void*, void*, int);
extern void fn_80128C28(void*, void*, int);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
extern void fn_80204810(void);

void fn_8009697C(register int index, register void* object,
                 register void* resource, void* random_context)
{
    register int random_value;
    register void* action;

    random_value = fn_80200C38(random_context);
    action = fn_801294DC(resource, 0x8E,
                         (unsigned short)(0x30 | (random_value != 0)), 8);
    if (action != 0) {
        index <<= 8;
        fn_80128C44(action, fn_80204810, index | 7);
        if (random_value == 0) {
            fn_80128C28(action, fn_80204810, index | 6);
        }
        fn_80201D2C(object, 0x4F);
        fn_80201D14(object, 1);
    }
}
