extern int fn_801B0B30(int);

int fn_800AF6DC(void)
{
    int result = 0;

    if (fn_801B0B30(0x1D) != -1) result = 1;
    if (fn_801B0B30(0x21) != -1) result = 1;
    if (fn_801B0B30(0x08) != -1) result = 1;
    if (fn_801B0B30(0x29) != -1) result = 1;
    if (fn_801B0B30(0x2CA) != -1) result = 1;
    if (fn_801B0B30(0x2D9) != -1) result = 1;
    if (fn_801B0B30(0x0B) != -1) result = 1;
    if (fn_801B0B30(0x3E) != -1) result = 1;
    if (fn_801B0B30(0x41) != -1) result = 1;
    if (fn_801B0B30(0x4E) != -1) result = 1;
    if (fn_801B0B30(0x24F) != -1) result = 1;
    return result;
}
