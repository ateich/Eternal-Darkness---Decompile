extern void* memcpy(void*, const void*, unsigned long);
extern unsigned char lbl_8060B204[];

int fn_801AD928(const void* source)
{
    memcpy(lbl_8060B204, source, 40);
    return 64;
}
