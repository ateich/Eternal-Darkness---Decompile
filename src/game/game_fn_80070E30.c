extern int lbl_8064D18C;
extern int fn_8015E4E8(void);
extern int fn_800460EC(void);
extern int fn_800A3564(void);

int fn_80070E30(void)
{
    if (fn_8015E4E8() != 0) return 0;
    if (fn_800460EC() != 0) return 0;
    if (lbl_8064D18C == 0x27 && fn_800A3564() == 3) return 0;
    return 1;
}
