typedef int s32;
typedef unsigned int u32;

extern const char lbl_8023BEF8[];
extern void* lbl_8064C4E0;
extern s32 lbl_8064C5D8;
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, s32, s32, ...);
extern void fn_80113B50(s32);
extern void fn_80113BA8(s32);
extern void fn_801E7974(void*, s32);
extern s32 fn_801E79FC(void*, s32);
extern void fn_80111C48(void);
extern s32 fn_80111780(void);
extern s32 fn_801118E8(void);

s32 fn_80012624(void* script)
{
    s32 value;

    value = (s32)script;
    if (fn_8016A598((void*)value) != 1) {
        fn_80163BB4((void*)value, lbl_8023BEF8, 1, fn_8016A598((void*)value));
        return 0;
    }

    value = (s32)fn_8016A694((void*)value, 1);
    if (value != 0) {
        if (value > 0) {
            fn_80113B50((u32)value << 18 >> 18);
            fn_80113BA8(((u32)value >> 16 & 7) << 16);
            if ((value & 0x70000) != 0) {
                fn_801E7974(lbl_8064C4E0, 0x1F3);
            }
            if ((value & 0x3FFF) != 0) {
                fn_801E7974(lbl_8064C4E0, 0x3DD);
            }
        }

        fn_80111C48();
        if (fn_80111780() != 0) {
            lbl_8064C5D8 = 1;
        }
        if (fn_801118E8() != 0
            && fn_801E79FC(lbl_8064C4E0, 0x3DE) == 0
            && fn_801E79FC(lbl_8064C4E0, 0x3DD) != 0) {
            fn_801E7974(lbl_8064C4E0, 0x3DD);
            lbl_8064C5D8 = 1;
        }
    }
    return 0;
}
