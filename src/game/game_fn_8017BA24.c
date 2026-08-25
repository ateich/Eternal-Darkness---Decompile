typedef unsigned char u8;

extern u8 lbl_8064A580[];

void* fn_8017BA24(void)
{
    u8 status = lbl_8064A580[0x10];
    void* value = *(void**)lbl_8064A580;
    if (status != 0) {
        return 0;
    }
    return value;
}
