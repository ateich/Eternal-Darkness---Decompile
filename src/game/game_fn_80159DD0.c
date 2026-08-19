extern char lbl_805B6FFC[];
extern void fn_8020D250(void*, unsigned int, int);

void fn_80159DD0(unsigned int value, unsigned int shift)
{
    fn_8020D250(lbl_805B6FFC, (value | 0x80000000) | (shift << 12), 1);
}
