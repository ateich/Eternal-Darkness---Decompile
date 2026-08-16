extern void* lbl_8064C4E0;
extern void fn_80201B44(void);
extern void* fn_80201814(void);
extern void* fn_80201C2C(void);
extern void* fn_802051A4(void*);
extern void fn_80205134(void*);
extern void* fn_80201C24(void);
extern void fn_801578A0(void*);
extern int fn_801E7578(void);
extern void fn_801E7974(void*, int);

void fn_8010ACF8(void)
{
    void* entry;

    fn_80201B44();
    fn_80201814();
    entry = fn_802051A4(fn_80201C2C());
    while (entry != 0) {
        fn_80205134(entry);
        if (fn_80201814() != 0) {
            fn_801578A0(fn_80201C24());
            if (fn_801E7578() > 1) {
                fn_801E7974(lbl_8064C4E0, 0x25B);
            }
        }
        entry = fn_802051A4(entry);
    }
}
