typedef struct Shared {
    int primary;
    int secondary;
    short requested;
    unsigned char pad[2];
    unsigned char* slots[2];
} Shared;

extern volatile Shared lbl_805B6FE0;

int fn_8015C71C(short value)
{
    if (*(short*)(lbl_805B6FE0.slots[lbl_805B6FE0.primary] + 0x8140) == value &&
        *(signed char*)(lbl_805B6FE0.slots[lbl_805B6FE0.primary] + 0x8143) != 0)
        return 2;

    if (lbl_805B6FE0.secondary != -1 &&
        *(short*)(lbl_805B6FE0.slots[lbl_805B6FE0.secondary] + 0x8140) == value &&
        *(signed char*)(lbl_805B6FE0.slots[lbl_805B6FE0.secondary] + 0x8143) != 0)
        return 3;

    return -1;
}
