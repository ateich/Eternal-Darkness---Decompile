typedef unsigned char u8;

extern u8 lbl_8064A580[];
extern int fn_8017B7FC(void);

void fn_8017B8BC(int value)
{
    if (value % fn_8017B7FC() == 0) {
        *(int*)(lbl_8064A580 + 0x1C) = value;
    }
}
