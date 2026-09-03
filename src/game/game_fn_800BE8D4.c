extern void* fn_80201B3C();
extern void* fn_80201B94();
extern int fn_80201C48(void *);
extern void fn_80201DD8(void *, int);
extern void fn_800C63D8(void);

void fn_800BE8D4(int value)
{
    void *object = fn_80201B3C();

    if (object != 0) {
        object = fn_80201B94(object);
        if (object != 0) {
            int id = fn_80201C48(object);
            if (id == value) {
                fn_80201DD8(object, 0);
                fn_800C63D8();
            }
        }
    }
}
