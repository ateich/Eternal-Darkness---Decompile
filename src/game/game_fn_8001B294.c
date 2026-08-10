typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern const char lbl_8023BEF8[];
extern void* lbl_8064C504;

extern s32 fn_8011804C(s32);
extern s32 fn_8016A598(void*);
extern void fn_8016A830(void*, double);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201814();
extern void* fn_80201B3C(void);
extern int fn_80201B44();
extern void* fn_80201C24(void*);
extern s32 fn_80038464(void*, s32, s16*);
extern s32 fn_80038308(void*, s32, s16*);
extern s32 fn_80157994(void*);
extern void fn_80157A28(void*, s32);
extern void* fn_801E6CA0(void*, s32, s32, s32, s32);
extern void fn_80027730(void*, s32, s32);

s32 fn_8001B294(void* script)
{
    void* manager;
    s32 id;
    s32 value;
    void* context;
    s16 first;
    s16 second;

    manager = fn_80201B3C();
    id = fn_8011804C(0);
    fn_80201B44();
    value = -1;

    if (fn_8016A598(script) != 0) {
        fn_80163BB4(script, lbl_8023BEF8, 0, fn_8016A598(script));
        return 0;
    }

    if (fn_80038464(manager, 1, &first) != 0 &&
        fn_80038308(manager, 1, &second) != 0) {
        context = fn_80201C24(fn_80201814(id));
        if (first != second) {
            fn_80157A28(context, (unsigned char)(fn_80157994(context) - 1));
            value = (u16)fn_80157994(context);
        } else {
            fn_80027730(fn_801E6CA0(lbl_8064C504, 0, 0x38, 0, 1), 0, 0);
        }
    }

    fn_8016A830(script, value);
    return 1;
}
