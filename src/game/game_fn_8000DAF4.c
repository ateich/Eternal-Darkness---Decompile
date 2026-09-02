typedef int s32;

extern const char lbl_8023BEF8[];
extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_8016A830(void*, double);
extern void* fn_80201B3C();
extern void* fn_80201C24();
extern void* fn_80049220(void*, s32);
extern s32 fn_80049304(void*, void*);
extern void* fn_802053B0(void*, void*);
extern int fn_80201B54();

s32 fn_8000DAF4(void* script)
{
    void* context;
    void* object;
    void* value;
    void* handle;

    context = fn_80201B3C();
    if (fn_8016A598(script) != 0) {
        fn_80163BB4(script, lbl_8023BEF8, 0, fn_8016A598(script));
        return 0;
    }

    value = fn_80049220(context, 1);
    fn_80049304(context, value);
    handle = fn_80201C24();
    object = fn_802053B0(context, handle);
    fn_8016A830(script, (double)(object != 0 ? fn_80201B54(object) : 0));
    return 1;
}
