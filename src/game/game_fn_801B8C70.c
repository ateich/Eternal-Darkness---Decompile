typedef unsigned int u32;

extern void fn_801CE2B8(void);
extern void fn_801CE280(void);
extern void fn_801B3B08(u32);

void fn_801B8C70(u32 handle)
{
    fn_801CE2B8();
    fn_801B3B08(handle);
    fn_801CE280();
}
