typedef int s32;
typedef unsigned int u32;
typedef unsigned long long u64;

extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, s32, ...);
extern void* fn_80201814(s32);
extern u64 fn_8020123C(s32, s32, s32, s32);
extern void fn_8016A830(void*, double);
extern void fn_8016A7D8(void*);
extern const double lbl_8064DCF8;
extern char lbl_8023BEF8[];

s32 fn_8001D3F8(void* script)
{
    s32 id;
    u32 message_result;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    id = (s32)fn_8016A694(script, 1);
    if (fn_80201814(id) != 0) {
        message_result = fn_8020123C(31, id, id, 0) & 0xFFFFFFFFULL;
        if (message_result != 0) {
            fn_8016A830(script, lbl_8064DCF8);
        } else {
            fn_8016A7D8(script);
        }
    }
    return 1;
}
