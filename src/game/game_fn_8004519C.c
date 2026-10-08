typedef unsigned char u8;
typedef unsigned int u32;

extern u8 fn_800451D4(void);
extern u32 fn_801E7578(u32 value);

u32 fn_8004519C(void)
{
    return fn_801E7578(fn_800451D4());
}
