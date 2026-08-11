typedef unsigned long long u64;
typedef unsigned int u32;
typedef int s32;

extern const char lbl_8023BEF8[];
extern double lbl_8064DCF8;
extern int fn_80201B44(void);
extern s32 fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern unsigned long long fn_8020123C();
extern void fn_8016A830(void*, double);
extern void* fn_80201814();
extern void fn_8016A7D8(void*);

s32 fn_80009FE4(void* script)
{
    register s32 handle;
    u32 message_result;

    handle = fn_80201B44();
    if (fn_8016A598(script) != 0) {
        fn_80163BB4(script, lbl_8023BEF8, 0, fn_8016A598(script));
        return 0;
    }
    message_result = fn_8020123C(0x34, handle, handle, 0) & 0xFFFFFFFFULL;
    if (message_result != 0) {
        fn_8016A830(script, lbl_8064DCF8);
    } else {
        fn_80201814(handle);
        fn_8016A7D8(script);
    }
    return 1;
}
