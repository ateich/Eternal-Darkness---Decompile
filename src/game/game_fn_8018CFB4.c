typedef unsigned short u16;

extern u16 lbl_80607130[];
extern void* memcpy(void*, const void*, unsigned int);

void fn_8018CFB4(void* dest, const void* src)
{
    memcpy(dest, src, lbl_80607130[5]);
    memcpy((char*)dest + lbl_80607130[1] * 6, src, lbl_80607130[5]);
}
