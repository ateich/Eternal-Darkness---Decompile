typedef unsigned char u8;

extern float lbl_80650D14;
extern void fn_801A19BC(void*);

void fn_801A1AB0(void* descriptor_)
{
    u8* descriptor = descriptor_;

    fn_801A19BC(descriptor);
    *(float*)(descriptor + 0x14) = lbl_80650D14;
    descriptor[0x19] = 0x1E;
    descriptor[0x18] = 0;
}
