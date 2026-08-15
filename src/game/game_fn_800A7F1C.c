extern void* fn_80201B3C(void*);
extern int fn_80036E50(void*);
extern void* fn_80201B44();
extern unsigned long long fn_8020123C();

void fn_800A7F1C(void* object)
{
    void* owner;

    if (fn_80036E50(fn_80201B3C(object)) != 1) {
        owner = fn_80201B44();
        fn_8020123C(0x87, object, owner, 0);
        fn_8020123C(8, object, owner, 0);
    }
}
