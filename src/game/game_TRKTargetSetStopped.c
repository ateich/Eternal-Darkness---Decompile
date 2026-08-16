extern unsigned char gTRKState[];

void TRKTargetSetStopped(int stopped)
{
    *(int *)(gTRKState + 0x98) = stopped;
}
