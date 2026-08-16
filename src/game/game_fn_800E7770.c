extern unsigned char lbl_80325DB8[10][16];
extern void *memset(void *, int, unsigned int);

void fn_800E7770(unsigned char index)
{
    memset(lbl_80325DB8[index], 0, 16);
}
