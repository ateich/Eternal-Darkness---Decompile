typedef unsigned long long u64;

extern void* fn_80201B9C();
extern int fn_80201B5C(void*);
extern int fn_80201EB8(void*);
extern void* fn_80201B54();
extern u64 fn_8020123C();
extern void* fn_80201BC0(void*);

void fn_800A18AC(register int owner)
{
    void* object = fn_80201B9C(owner);
    int candidate;

    while (object != 0) {
        if (fn_80201B5C(object) == 3) {
            candidate = fn_80201EB8(object);
            if (candidate == owner) {
                fn_8020123C(0xE5, 0, fn_80201B54(object), 0);
            }
        }
        object = fn_80201BC0(object);
    }
}
