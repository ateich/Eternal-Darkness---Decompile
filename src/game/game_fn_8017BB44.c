typedef unsigned short u16;

extern unsigned char lbl_8064A7C8[];

void* fn_8017BB44(void)
{
    u16* state = (u16*)lbl_8064A7C8;
    return lbl_8064A7C8 + state[1] * 0x48 + 8;
}
