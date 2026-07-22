typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct RootState {
    void* value;
    unsigned char pad_04[4];
    int mode_08;
    unsigned char pad_0C[4];
} RootState;

extern u32 lbl_8064C5F4;
extern void* lbl_8064C5F8;
extern int lbl_8064C5F0;
extern void* lbl_8064C4E0;
extern RootState lbl_803003C8;
extern unsigned char lbl_8023BAA0[];

extern void fn_80006974(void);
extern void* fn_80144628(int, void*, int);
extern void fn_801446D4(void*, void (*)(void));
extern int fn_80201B44(void);
extern void fn_80201814(void);
extern u32 fn_8020216C(void);
extern int fn_801E79FC(void*, int);
extern u64 fn_8020123C(int, int, int, int);
extern void fn_801D0050(int, int);
extern void fn_80144C40(void);
extern int fn_800EB744(void);
extern void fn_80144C4C(void*);

void fn_800069DC(u32 value)
{
    u32 current = lbl_8064C5F4;
    if (value > current) {
        current = value;
    }
    lbl_8064C5F4 = current;
}

#pragma dont_inline on
u32 fn_800069F4(void)
{
    return lbl_8064C5F4;
}
#pragma dont_inline reset

void* fn_800069FC(void)
{
    lbl_8064C5F8 = fn_80144628(11, lbl_8023BAA0, 0);
    fn_801446D4(lbl_8064C5F8, fn_80006974);
    lbl_8064C5F0 = 0;
    lbl_8064C5F4 = 0;
    return lbl_8023BAA0;
}

void fn_80006A50(int unused, int value)
{
    u32 result;

    fn_80201B44();
    fn_80201814();

    if ((fn_8020216C() & 0x4000) == 0) {
        if (lbl_803003C8.mode_08 == 1) {
            return;
        }
        if (lbl_803003C8.mode_08 == 2) {
            return;
        }
        if (lbl_803003C8.mode_08 == 0) {
            if (fn_801E79FC(lbl_8064C4E0, 0x133) == 0) {
                return;
            }
        }
    }

    if (fn_800069F4() == 0) {
        result = fn_8020123C(0xB9, 0, fn_80201B44(), 0) & 0xFFFFFFFFULL;
        if (result == 1) {
            fn_801D0050(1, value);
        }
    }
    fn_80144C40();
}

void fn_80006B08(void)
{
    if (fn_800EB744() == 0) {
        fn_80144C4C(lbl_8064C5F8);
    }
}
