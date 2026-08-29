typedef unsigned char u8;

extern float lbl_80650D18;
extern void fn_801A1A04(void*);

void fn_801A1AF4(void* descriptor_)
{
    u8* descriptor = descriptor_;

    fn_801A1A04(descriptor);
    *(float*)(descriptor + 0x14) = lbl_80650D18;
    descriptor[0x19] = 0;
    descriptor[0x18] = 0;
}
