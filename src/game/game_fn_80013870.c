typedef int s32;

extern const char lbl_8023BEF8[];
extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern unsigned int fn_800F5C54(double);
extern s32 fn_8011804C(s32);
extern void fn_8016A830(void*, double);

s32 fn_80013870(void* script)
{
    void* parser = script;
    s32 result;

    if (fn_8016A598(parser) != 1) {
        fn_80163BB4(parser, lbl_8023BEF8, 1, fn_8016A598(parser));
        return 0;
    }

    result = fn_8011804C(fn_800F5C54(fn_8016A694(parser, 1)));
    fn_8016A830(parser, (double)result);
    return 1;
}
