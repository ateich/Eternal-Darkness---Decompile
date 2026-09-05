typedef unsigned int u32;
extern u32 fn_801B5B68(u32 value);

void fn_801CC418(u32* value, u32 divisor)
{
    divisor = fn_801B5B68(divisor);
    *value = (((*value << 16) / divisor) * 1000) >> 5;
}
