typedef signed char s8;
typedef unsigned char u8;
typedef unsigned int u32;

extern u8* fn_8015C28C(int);

int fn_8015ABD4(int index, u8 mask)
{
    u8* state = fn_8015C28C(index);
    int result = 0;

    if ((s8)state[0x8143] != 0 && (s8)state[0x8142] != 0) {
        result = (*(u32*)(state + 0x24) & mask) != 0;
    }

    return result;
}
