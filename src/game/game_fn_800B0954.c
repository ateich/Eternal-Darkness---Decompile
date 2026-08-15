typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Header800B0954 {
    unsigned char pad_00[32];
    u16 firstSize;
    u16 secondSize;
    u32 firstCheck;
    u32 secondCheck;
    unsigned char pad_2C[20];
} Header800B0954;

extern void* memcpy(void*, const void*, unsigned int);
extern u32 fn_801E7454(void*, u16);

int fn_800B0954(unsigned char* data)
{
    Header800B0954 header;
    u32 check;
    int offset;

    memcpy(&header, data, 64);
    check = fn_801E7454(data + 64, header.firstSize);
    if (check != header.firstCheck) {
        return 0;
    }
    offset = 64;
    offset += header.firstSize;
    check = fn_801E7454(data + offset, header.secondSize);
    return check == header.secondCheck;
}
