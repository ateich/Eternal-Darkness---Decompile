typedef unsigned int u32;

extern volatile u32 __SIRegs[] : 0xCC006400;

void fn_80208EE8(void)
{
    __SIRegs[14] = 0x80000000;
}
