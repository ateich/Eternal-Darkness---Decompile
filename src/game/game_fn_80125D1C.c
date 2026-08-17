typedef unsigned short u16;

typedef struct Header {
    u16 unused;
    u16 unused2;
    u16 size;
    u16 version;
} Header;

int fn_80125D1C(Header* header)
{
    int valid = 1;
    valid &= header->size == 0x48;
    valid &= header->version == 0x1E;
    return valid;
}
