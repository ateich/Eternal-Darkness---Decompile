typedef unsigned char u8;

int fn_8012AFE8(u8* state)
{
    unsigned short flags = *(unsigned short*)(state + 0xF8);
    int result = 0;

    if (((flags & 2) != 0 || (flags & 1) != 0) &&
        (*(unsigned int*)(state + 0xF4) & 0x100) == 0) {
        result = 1;
    }
    return result;
}
