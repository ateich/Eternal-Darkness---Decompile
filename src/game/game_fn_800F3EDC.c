extern unsigned char gTRKCPUState[];

unsigned int fn_800F3EDC(void)
{
    return *(unsigned int *)(gTRKCPUState + 0x80);
}
