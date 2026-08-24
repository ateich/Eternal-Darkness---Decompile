typedef int s32;

extern const char lbl_8023BEF8[];
extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_800E463C(void);
extern void fn_800E4648(void);
extern void fn_800E4674(void);

s32 fn_80013748(void* script)
{
    void* parser = script;

    if (fn_8016A598(parser) != 1) {
        fn_80163BB4(parser, lbl_8023BEF8, 1, fn_8016A598(parser));
        return 0;
    }

    if ((s32)fn_8016A694(parser, 1) != 0) {
        fn_800E463C();
        fn_800E4648();
    } else {
        fn_800E4674();
    }
    return 0;
}
