extern void* memcpy(void*, const void*, unsigned long);
extern unsigned char lbl_8060B204[];

int fn_801AD8F8(void* destination)
{
    memcpy(destination, lbl_8060B204, 40);
    return 64;
}
