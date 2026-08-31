typedef unsigned int u32;

extern void* fn_801AC7BC(u32);

int fn_801AC9C0(u32 key)
{
    void* effect = fn_801AC7BC(key);
    int result;

    if (effect != 0) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}
