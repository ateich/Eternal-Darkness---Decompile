typedef signed char s8;
typedef unsigned char u8;

extern u8* fn_8015C28C(int);

void* fn_8015AB8C(int index)
{
    u8* state = fn_8015C28C(index);
    void* result = 0;

    if ((s8)state[0x8143] != 0 && (s8)state[0x8142] != 0) {
        result = *(void**)(state + 0x84);
    }

    return result;
}
