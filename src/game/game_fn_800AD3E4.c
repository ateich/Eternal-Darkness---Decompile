extern int lbl_803003C8[];
extern int lbl_8064C98C;
extern void *fn_80201814();
extern int fn_80201B64(void);

int fn_800AD3E4(void)
{
    if (lbl_803003C8[2] == 13 && fn_80201814(lbl_8064C98C) != 0) {
        return fn_80201B64();
    }
    return -1;
}
