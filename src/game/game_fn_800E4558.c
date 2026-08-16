extern int fn_80200614(int, int, int);

int fn_800E4558(int value)
{
    int result = 0;

    if (value > 0)
        result = fn_80200614(value, -1, 18);
    return result;
}
