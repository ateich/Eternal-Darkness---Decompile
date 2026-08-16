extern unsigned char gTRKState[];

int TRKTargetStopped(void)
{
    return *(int *)(gTRKState + 0x98);
}
