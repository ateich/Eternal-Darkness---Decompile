extern void* fn_80049194(void);
extern unsigned int fn_801A6D9C(void* object);

unsigned int fn_80050A20(void)
{
    return (fn_801A6D9C(fn_80049194()) >> 5) & 1;
}
