typedef int s32;

extern const char lbl_80244EDC[];
extern const char lbl_80244F0C[];
extern unsigned char lbl_8031CD84[];
extern s32 lbl_8064C8F0;
extern const double lbl_8064EA40;

extern int fn_8016A598(void *);
extern void *fn_8016A784(void *, int);
extern double fn_8016A694(void *, int);
extern void fn_80163BB4(void *, const char *, ...);
extern unsigned int fn_801E741C(const char *);

s32 fn_8007F650(void *script)
{
    void *object;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_80244EDC, 1, fn_8016A598(script));
        return 0;
    }

    object = fn_8016A784(script, 1);
    if (object != 0) {
        if ((signed char)lbl_8031CD84[0x631] == 0) {
            lbl_8031CD84[0x631] = 1;
            if (*(unsigned int *)((unsigned char *)object + 0x2C) == fn_801E741C(lbl_80244F0C)) {
                lbl_8064C8F0 = (signed char)lbl_8031CD84[0x630];
            } else {
                lbl_8064C8F0 = 3;
            }
        }
    } else if (fn_8016A694(script, 1) == lbl_8064EA40) {
        lbl_8031CD84[0x631] = 1;
        lbl_8064C8F0 = (signed char)lbl_8031CD84[0x630];
    } else {
        lbl_8031CD84[0x631] = 0;
    }

    return 0;
}
