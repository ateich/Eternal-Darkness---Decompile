typedef signed short s16;
typedef unsigned char u8;

typedef struct TypeDescriptor {
    u8 pad[16];
    s16 value;
    u8 tail[6];
} TypeDescriptor;

extern void fn_800EE444(void);

extern TypeDescriptor lbl_802417D0[];
extern u8 lbl_8030F540[];
extern int lbl_8064C6D4;

void fn_8005251C(void)
{
    lbl_8064C6D4 = 1;

    if (lbl_802417D0[lbl_8030F540[0x1DA]].value != -1) {
        lbl_8030F540[0x1E4] = 1;
    }

    lbl_8030F540[0x1D9] = 1;
    fn_800EE444();
}
