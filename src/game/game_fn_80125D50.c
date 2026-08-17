typedef unsigned short u16;

typedef struct Header {
    u16 magic;
    u16 version;
} Header;

int fn_80125D50(Header* header)
{
    int version;
    int new_enough;

    version = header->version;
    new_enough = 0;
    if (version >= 45)
        new_enough = 1;
    return new_enough && header->magic == 252;
}
