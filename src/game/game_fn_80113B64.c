extern unsigned int lbl_80331748[];

extern int fn_80201B44();
extern void* fn_80201814();
extern int fn_8020216C(void);

unsigned int fn_80113B64(void)
{
    int result;
    unsigned int mask;

    fn_80201B44();
    fn_80201814();
    result = fn_8020216C();
    mask = 0x3FFF3FFF;
    if (result == 0) {
        mask = lbl_80331748[0] & mask;
    }
    return mask;
}
