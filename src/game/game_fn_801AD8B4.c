extern void fn_801AD46C(unsigned char*, unsigned char*);
extern void fn_801ACCA0(unsigned char, unsigned char);

void fn_801AD8B4(void)
{
    unsigned char first;
    unsigned char second;

    fn_801AD46C(&first, &second);
    fn_801ACCA0(first, second);
}
