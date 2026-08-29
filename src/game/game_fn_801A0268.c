typedef unsigned char u8;

void fn_801A0268(void* object_, void* descriptor_)
{
    u8* object = object_;
    u8* descriptor = descriptor_;

    *(float*)(object + 0x8C) = *(float*)(descriptor + 0x14);
    *(float*)(object + 0x90) = *(float*)(descriptor + 0x18);
    *(float*)(object + 0x94) = *(float*)(descriptor + 0x1C);
}
