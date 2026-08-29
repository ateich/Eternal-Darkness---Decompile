typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void* memcpy(void* destination, const void* source, unsigned long count);

void fn_8019475C(u8* output, const void* fallback, void* unused, const u8* input)
{
    if ((*(const u32*)(input + 0x38) & 0x40000) != 0) {
        memcpy(output + 0x10, input + 0x1C, 6);
    } else {
        memcpy(output + 0x10, fallback, 6);
    }

    output[1] = input[0x17] - 2;
    output[0] = 0x80;
    *(u16*)(output + 0x0A) = 0;
    *(u32*)(output + 0x44) = 0;
    *(u16*)(output + 0x0C) = *(const u16*)(input + 6);
    *(short*)(output + 0x0E) = -1;
    output[3] = 4;
}
