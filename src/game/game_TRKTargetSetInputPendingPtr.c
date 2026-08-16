extern unsigned char gTRKState[];

void TRKTargetSetInputPendingPtr(void *pending)
{
    *(void **)(gTRKState + 0xA0) = pending;
}
