typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern volatile s32 lbl_8064B818;

s32 fn_8000D8A4(void* script)
{
    s32 value;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    value = (s32)fn_8016A694(script, 1);
    switch (value) {
    case -1:
        lbl_8064B818 = value;
        break;
    case 0:
        lbl_8064B818 = value;
        break;
    case 1:
        lbl_8064B818 = value;
        break;
    case 2:
        lbl_8064B818 = value;
        break;
    case 3:
        lbl_8064B818 = value;
        break;
    case 4:
        lbl_8064B818 = value;
        break;
    case 5:
        lbl_8064B818 = value;
        break;
    }
    return 0;
}
