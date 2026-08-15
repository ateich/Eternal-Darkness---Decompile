extern void *fn_80201B3C(void);
extern void *fn_80201B94(void *);
extern void fn_80201DD8(void *, int);
extern void fn_800C63D8(void);

void fn_800BE894(void)
{
    void *object = fn_80201B3C();

    if (object != 0) {
        object = fn_80201B94(object);
        if (object != 0) {
            fn_80201DD8(object, 0);
            fn_800C63D8();
        }
    }
}
