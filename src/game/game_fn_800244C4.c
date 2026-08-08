typedef unsigned int u32;

extern void fn_800244F4(void*, u32*, u32, u32);

u32 fn_800244C4(void* object, u32 first, u32 second)
{
    u32 result;

    fn_800244F4(object, &result, first, second);
    return result;
}
