extern unsigned char gTRKCPUState[];
extern unsigned int lbl_8032A568;

unsigned int fn_800F5030(unsigned int address)
{
    unsigned int base = lbl_8032A568;

    if (address >= base && address < base + 0x4000 &&
        (*(unsigned int *)(gTRKCPUState + 0x238) & 3) != 0) {
        return address;
    }
    return (address & 0x3FFFFFFF) | 0x80000000;
}
