typedef unsigned char u8;

extern void* lbl_8064C4E4;
extern void* lbl_8064C824;

extern int fn_801A5CE0(void);
extern u8 fn_80128EE4(void* object);
extern int fn_801A6D94(void* object);
extern int fn_801D0CD8(void);
extern void* fn_80201B3C(void);
extern int fn_80201B64(void* object);

int fn_8004919C(void)
{
    int enabled = 1;

    if (fn_801A5CE0() != 0) {
        if ((fn_80128EE4(lbl_8064C4E4) & 8) != 0) {
            enabled = 0;
        }
        if (fn_801A6D94(lbl_8064C824) != 0) {
            enabled = 0;
        }
    }
    if (fn_801D0CD8() == 0) {
        enabled = 0;
    }
    if (fn_80201B64(fn_80201B3C()) == 8) {
        enabled = 0;
    }
    return enabled;
}
