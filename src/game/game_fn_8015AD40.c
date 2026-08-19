typedef signed char s8;
typedef unsigned char u8;

extern u8* fn_8015C28C(int);

int fn_8015AD40(int index)
{
    u8* state = fn_8015C28C(index);
    int result = -1;

    if ((s8)state[0x8143] != 0 && (s8)state[0x8142] != 0) {
        result = *(short*)(state + 0x88);
    }

    return result;
}
