typedef unsigned short u16;

extern unsigned char lbl_8064A7C8[];

int fn_8017BB24(void)
{
    u16* state = (u16*)lbl_8064A7C8;
    return state[0] == state[1];
}
