typedef unsigned int u32;

extern u32 PPCMfmsr(void);
extern void PPCMtmsr(u32 value);
extern void fn_80209BB4(void);

void __DBExceptionDestination(void)
{
    u32 msr = PPCMfmsr();

    PPCMtmsr(msr | 0x30);
    fn_80209BB4();
}
