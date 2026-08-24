typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern const char lbl_8023BEF8[];
extern void* lbl_8064C504;

extern s32 fn_8011804C(s32);
extern int fn_8016A598(void*);
extern void fn_8016A830(void*, double);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern void* fn_80201B3C();
extern int fn_80201B44();
extern void* fn_80201C24();
extern int fn_80038464(void*, int, s16*);
extern int fn_80038308(void *, int, short *);
extern s32 fn_80157994(void*);
extern void fn_80157A28(void*, s32);
extern void* fn_801E6CA0(void*, int, int, int, int);
extern void fn_80027730(void*, s32, s32);

s32 fn_8001B294(void* script)
{
    register void* manager;
    register s32 id;
    register s32 value;
    register void* parser;
    s16 first;
    s16 second;

    parser = script;
    manager = fn_80201B3C();
    id = fn_8011804C(0);
    fn_80201B44();
    value = -1;

    if (fn_8016A598(parser) != 0) {
        fn_80163BB4(parser, lbl_8023BEF8, 0, fn_8016A598(parser));
        return 0;
    }

    if (fn_80038464(manager, 1, &first) != 0 &&
        fn_80038308(manager, 1, &second) != 0) {
        manager = fn_80201C24(fn_80201814(id));
        if (first != second) {
            fn_80157A28(manager, (unsigned char)(fn_80157994(manager) - 1));
            value = fn_80157994(manager) & 0xFFFF;
        } else {
            fn_80027730(fn_801E6CA0(lbl_8064C504, 0, 0x38, 0, 1), 0, 0);
        }
    }

    fn_8016A830(parser, value);
    return 1;
}
