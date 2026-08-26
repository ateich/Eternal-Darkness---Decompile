typedef unsigned char u8;
typedef unsigned int u32;

extern u8 lbl_8064C268;
extern u8 lbl_80606318[];
extern u8 lbl_80606328[];
extern void* lbl_8064D224;
extern void* lbl_8064D228;
extern void* lbl_8064D22C;
extern u8 lbl_8064D258;

extern void fn_800246B8(void*, u32, void**, u32, void**, void*);
extern void fn_801A0450(void);
extern void fn_801EF364(void*);

void fn_8017FFC0(void)
{
    fn_801A0450();
    fn_800246B8(&lbl_8064C268, (u32)lbl_80606318, &lbl_8064D228,
                (u32)lbl_80606328, &lbl_8064D22C, &lbl_8064D224);
    fn_801EF364(lbl_8064D224);
    lbl_8064D258 = 0;
}
