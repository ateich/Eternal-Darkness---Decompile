typedef struct RuntimeInfo80093148 {
    unsigned char pad00[0x8C];
    void* value8C;
} RuntimeInfo80093148;

extern void* fn_80201B3C(void);
extern int fn_800359A0(void*, void*);
extern RuntimeInfo80093148*fn_80201B8C();
extern void fn_800BDEE4(void*, void*);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);

int fn_80093148(register void* object, void* unused)
{
    void* current = fn_80201B3C();
    int result;

    result = 0;
    if (fn_800359A0(object, current)) {
        fn_800BDEE4(object, fn_80201B8C(object)->value8C);
        fn_80201D2C(object, 3);
        fn_80201D14(object, 1);
        result = 1;
    }
    return result;
}
