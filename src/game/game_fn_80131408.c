typedef struct Header {
    char pad_0[0xC];
    unsigned int first;
    unsigned int second;
    char pad_14[0x24];
    unsigned int third;
} Header;

extern int lbl_8064CF44;
extern char lbl_8030F540[];

void fn_80131408(Header* header)
{
    lbl_8064CF44 = 1;
    if (header->first != 0) {
        header->first = (unsigned int)header + header->first;
    }
    if (header->second != 0) {
        header->second = (unsigned int)header + header->second;
    }
    header->third = (unsigned int)header + header->third;
    *(int*)(lbl_8030F540 + 0x1C8) = -1;
}
