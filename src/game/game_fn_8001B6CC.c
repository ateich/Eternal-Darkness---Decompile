typedef int s32;

extern const char lbl_8023BEF8[];

extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201814();
extern void* fn_80201BC8();
extern s32 fn_8011EB04(void);
extern void* fn_80201C24();
extern void fn_80157B94(void*, s32);

s32 fn_8001B6CC(void* script)
{
    s32 state;
    void* object;
    void* object_state;
    s32 value;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    object = fn_80201814((s32)fn_8016A694(script, 1));
    if (object != 0 && fn_80201BC8() != 0) {
        state = fn_8011EB04();
        object_state = fn_80201C24(object);
        switch (state) {
    case 32:
        value = 9;
        break;
    case 33:
        value = 12;
        break;
    case 34:
        value = 15;
        break;
    case 35:
        value = 41;
        break;
    case 36:
        value = 18;
        break;
    case 37:
        value = 22;
        break;
    case 39:
        value = 25;
        break;
    case 40:
        value = 28;
        break;
    case 41:
        value = 38;
        break;
    case 42:
        value = 1;
        break;
    case 43:
        value = 3;
        break;
    case 44:
        value = 35;
        break;
        default:
            return 0;
        }
        fn_80157B94(object_state, value);
    }
    return 0;
}
