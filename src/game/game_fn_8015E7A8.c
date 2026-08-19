typedef unsigned char u8;
typedef struct Entry {
    u8 pad0[0x10];
    void* data;
    u8 pad14[4];
} Entry;

extern int lbl_8064D178;
extern Entry lbl_805B6F80[];
extern void* lbl_8064D1B4;

void* fn_8015E7A8(void)
{
    return lbl_8064D1B4 = lbl_805B6F80[lbl_8064D178].data;
}
