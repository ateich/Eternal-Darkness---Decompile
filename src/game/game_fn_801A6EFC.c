extern void* fn_801FEA8C(unsigned int, int, const char*, int);
extern void* fn_8017CCD8(void*, unsigned int, unsigned short);
extern void* memset(void*, int, unsigned int);
extern const char lbl_802513A8[];
extern void* lbl_8064D274;
extern void* lbl_80607C10[];

void fn_801A6EFC(unsigned short count)
{
    void* storage = fn_801FEA8C(count * 0xD4, 1, lbl_802513A8, 0x3A);
    lbl_8064D274 = fn_8017CCD8(storage, 0xD4, count);
    memset(lbl_80607C10, 0, 0xA0);
}
