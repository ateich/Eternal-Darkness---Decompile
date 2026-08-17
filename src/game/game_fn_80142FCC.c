typedef unsigned char u8;
extern u8 lbl_8064D038;
extern void* memset(void*, int, unsigned int);

void fn_80142FCC(void* slot)
{
    memset(slot, 0, 0x14);
    lbl_8064D038--;
}
