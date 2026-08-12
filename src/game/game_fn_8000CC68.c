typedef int s32;
typedef signed short s16;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern int fn_800389E0(void*, int, s32, int);
extern void fn_80038544(s32, s32, s32);
extern void fn_80038878(s32, s32, s32);
extern void fn_80038650(s32, s32, s32, s32);
extern void fn_800387FC(s32, s32, s16);

s32 fn_8000CC68(void* script)
{
    s32 index;
    s32 value;
    s32 extra;
    s32 id;
    s32 kind;
    void* object;

    if (fn_8016A598(script) != 5) {
        fn_80163BB4(script, lbl_8023BEF8, 5, fn_8016A598(script));
        return 0;
    }

    id = (s32)fn_8016A694(script, 1);
    index = (s32)fn_8016A694(script, 2);
    value = (s32)fn_8016A694(script, 3);
    kind = (s32)fn_8016A694(script, 4);
    extra = (s32)fn_8016A694(script, 5);
    object = fn_80201814(id);
    if (object != 0) {
        switch (kind) {
        case 1:
            if (index == 15) {
                fn_800389E0(object, 0, value, 0);
            } else {
                fn_80038544(id, index, value);
            }
            break;
        case 2:
            if (index == 15) {
                fn_80038878(id, 0, value);
            } else {
                fn_80038650(id, index, value, extra);
            }
            break;
        case 3:
            fn_800387FC(id, index, (s16)value);
            break;
        }
    }
    return 0;
}
