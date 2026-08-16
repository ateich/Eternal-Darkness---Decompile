int fn_800F92D0(void* stream, long offset, int origin);

int fseek(void* stream, long offset, int origin)
{
    return fn_800F92D0(stream, offset, origin);
}
