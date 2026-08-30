typedef unsigned short u16;
typedef unsigned int u32;

extern const float lbl_80650DD8;

void fn_801A6D40(void* state)
{
    unsigned char* data = state;
    *(u32*)(data + 0x00) = 0;
    *(u32*)(data + 0x04) = 0;
    *(u32*)(data + 0x08) = 0;
    *(u32*)(data + 0x0C) = 0x10000;
    *(int*)(data + 0x10) = -1;
    *(float*)(data + 0x14) = lbl_80650DD8;
    *(float*)(data + 0x18) = lbl_80650DD8;
    *(float*)(data + 0x1C) = lbl_80650DD8;
    *(float*)(data + 0x20) = lbl_80650DD8;
    *(float*)(data + 0x24) = lbl_80650DD8;
    *(u32*)(data + 0x28) = 0;
    *(u32*)(data + 0x2C) = 0;
    *(u32*)(data + 0x30) = 0x10000;
    *(u16*)(data + 0x34) = 0;
    *(u16*)(data + 0x36) = 0;
    *(u16*)(data + 0x38) = 0;
}
