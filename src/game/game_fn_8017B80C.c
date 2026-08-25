typedef unsigned int u32;
typedef unsigned char u8;

extern u8 lbl_8064A580[];
extern int fn_8017B7FC(void);

void fn_8017B80C(u32 value)
{
    if (value % fn_8017B7FC() == 0) {
        *(u32*)(lbl_8064A580 + 0x14) = value;
    }
}
