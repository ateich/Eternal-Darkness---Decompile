typedef signed int s32;
typedef unsigned int u32;

extern volatile u32 __SIRegs[] : 0xCC006400;

void fn_80208ED4(s32 chan, u32 value)
{
    __SIRegs[chan * 3] = value;
}
