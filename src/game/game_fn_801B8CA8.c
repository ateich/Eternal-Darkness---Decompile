typedef unsigned int u32;

extern void fn_801CE2B8(void);
extern void fn_801CE280(void);
extern void fn_801B3C14(u32, u32, u32);

void fn_801B8CA8(u32 handle, u32 value1, u32 value2)
{
    fn_801CE2B8();
    fn_801B3C14(handle, value1, value2);
    fn_801CE280();
}
