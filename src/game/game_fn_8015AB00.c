typedef signed char s8;
typedef unsigned char u8;

extern void* fn_8015AABC(void);
extern u8* fn_8015C28C(int);

void* fn_8015AB00(int index)
{
    void* result = fn_8015AABC();

    if (result == 0) {
        u8* state = fn_8015C28C(index);

        if ((s8)state[0x8143] != 0 && (s8)state[0x8142] != 0) {
            result = *(void**)(state + 0x7C);
        }
    }

    return result;
}
