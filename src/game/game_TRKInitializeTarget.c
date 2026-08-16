extern unsigned char gTRKState[];
extern unsigned int lbl_8032A568;

unsigned int fn_800F36A0(void);

int TRKInitializeTarget(void)
{
    *(int *)(gTRKState + 0x98) = 1;
    *(unsigned int *)(gTRKState + 0x8C) = fn_800F36A0();
    lbl_8032A568 = 0xE0000000;
    return 0;
}
