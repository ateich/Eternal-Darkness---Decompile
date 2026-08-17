typedef struct Header {
    unsigned char pad[0x14];
    void* entries;
} Header;

void* fn_8013898C(Header* header)
{
    return header->entries;
}
