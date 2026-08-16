extern unsigned char gTRKState[];

int fn_800F3C60(void)
{
    *(int *)(gTRKState + 0x98) = 1;
    return 0;
}
