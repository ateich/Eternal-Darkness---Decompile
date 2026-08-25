typedef unsigned char u8;

extern u8 lbl_8064A580[];
extern u8 lbl_8064A6F0[];

void* fn_8017B9C4(int index)
{
    if (lbl_8064A580[index + 0x40] != 0) {
        return lbl_8064A6F0 + index * 0x6C;
    }
    return 0;
}
