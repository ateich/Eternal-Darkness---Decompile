extern int fn_800FBFB0(void);

void* fn_801A9F44(int count, void** values)
{
    void* result = 0;

    if (count != 0 && values != 0) {
        result = values[fn_800FBFB0() % count];
    }
    return result;
}
