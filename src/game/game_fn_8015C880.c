typedef struct Shared {
    int primary;
    int secondary;
    short requested;
    unsigned char pad[2];
    unsigned char* slots[2];
} Shared;

extern volatile Shared lbl_805B6FE0;

void fn_8015C880(void)
{
    lbl_805B6FE0.slots[lbl_805B6FE0.primary][0x8142] = 0;
}
