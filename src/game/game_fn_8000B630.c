typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201814();
extern void* fn_80201BC8();
extern s32 fn_80128EAC(void*);
extern void fn_8016A830(void*, double);

s32 fn_8000B630(void* script)
{
    s32 result = 0;
    void* object;
    void* info;
    s32 type;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    object = fn_80201814((s32)fn_8016A694(script, 1));
    info = object != 0 ? fn_80201BC8(object) : 0;
    if (object != 0 && info != 0) {
        type = fn_80128EAC(info);
        switch (type) {
        case 46:
        case 47:
        case 157:
            result = 1;
            break;
        }
    }
    fn_8016A830(script, result);
    return 1;
}
