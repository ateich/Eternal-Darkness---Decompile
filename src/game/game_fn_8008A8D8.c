typedef signed int s32;

extern void *fn_80201814();
extern void *fn_80201BC8();
extern void* fn_801294DC(void*, s32, s32, s32);

s32 fn_8008A8D8(void* unused, void* object)
{
    fn_80201814(object);
    fn_801294DC(fn_80201BC8(), 0x28, 0x21, 0xA);
    return 1;
}
