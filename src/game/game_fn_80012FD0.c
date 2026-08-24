typedef int s32;

typedef struct ObjectInfo {
    char pad0[0x94];
    s32 value;
} ObjectInfo;

extern const char lbl_8023BEF8[];
extern const double lbl_8064DCE8;
extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern void *fn_80201B8C();
extern void fn_8016A830(void*, double);

s32 fn_80012FD0(void* script)
{
    register s32 value = 0;
    register void* parser = script;
    void* object;
    ObjectInfo* info;

    if (fn_8016A598(parser) != 1) {
        fn_80163BB4(parser, lbl_8023BEF8, 1, fn_8016A598(parser));
        return 0;
    }

    object = fn_80201814((s32)fn_8016A694(parser, 1));
    if (object != 0) {
        info = fn_80201B8C(object);
        if (info != 0) {
            value = info->value;
        }
    }

    fn_8016A830(parser, (double)value);
    return 1;
}
