extern int fn_800FBFB0(void);

int fn_801A9EF4(int low, int high)
{
    int random = fn_800FBFB0();
    int range = high - low + 1;

    return low + random % range;
}
