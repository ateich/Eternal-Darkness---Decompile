typedef unsigned long long u64;
typedef unsigned int u32;
typedef int s32;

#pragma use_lmw_stmw on

extern const char lbl_8023BEF8[];
extern s32 fn_800DE3F8(void);
extern s32 fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern int fn_80201B44(void);
extern unsigned long long fn_8020123C();
extern void fn_8016A830(void*, double);

s32 fn_800099D8(void* script)
{
    s32 handle;
    u32 message_result;
    s32 result;

    handle = fn_800DE3F8();
    result = 0;
    if (fn_8016A598(script) != 0) {
        fn_80163BB4(script, lbl_8023BEF8, 0, fn_8016A598(script));
        return 0;
    }

    if (handle != 0) {
        message_result =
            fn_8020123C(0x3B, fn_80201B44(), handle, 0) & 0xFFFFFFFFULL;
        if (message_result != 0) {
            result = 1;
        }
    }

    fn_8016A830(script, (double)result);
    return 1;
}
