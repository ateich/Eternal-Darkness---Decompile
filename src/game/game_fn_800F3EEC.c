typedef struct TRKExceptionStatus {
    unsigned int active;
    unsigned char kind;
    unsigned char pad[3];
    unsigned int count;
    unsigned int start;
    unsigned int end;
} TRKExceptionStatus;

extern unsigned char gTRKCPUState[];
extern unsigned char gTRKState[];
extern TRKExceptionStatus lbl_8024A874;

int fn_800F3EEC(unsigned int start, unsigned int end, int invalid)
{
    unsigned int kind = 1;

    if (invalid != 0) {
        return 0x703;
    }

    lbl_8024A874.kind = kind;
    *(unsigned int *)(gTRKCPUState + 0x1F8) |= 0x400;
    lbl_8024A874.start = start;
    lbl_8024A874.end = end;
    lbl_8024A874.active = 1;
    if (kind == 0 || kind == 0x10) {
        lbl_8024A874.count--;
    }
    *(unsigned int *)(gTRKState + 0x98) = 0;
    return 0;
}
