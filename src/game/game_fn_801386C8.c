typedef unsigned char u8;

extern u8* lbl_8064CFF8;
extern void* memset(void*, int, unsigned int);

void fn_801386C8(int index)
{
    memset(lbl_8064CFF8 + index * 0x2F8, 0, 0x2F8);
}
