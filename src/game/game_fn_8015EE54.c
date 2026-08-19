extern int fn_8015F9B0(void*, int, int);

int fn_8015EE54(void* object, int value)
{
    if (value > 0)
        return fn_8015F9B0(object, 5, value);
    return fn_8015F9B0(object, 4, -value);
}
