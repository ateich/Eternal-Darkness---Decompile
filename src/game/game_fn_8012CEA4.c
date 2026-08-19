typedef unsigned char u8;

typedef struct Vec4 {
    float x;
    float y;
    float z;
    float w;
} Vec4;

extern void fn_80125ECC(void *);
extern void fn_8012BE64(void*, Vec4*);

void fn_8012CEA4(u8* state, int index, Vec4* value)
{
    u8* entry;

    fn_80125ECC(state);
    entry = *(u8**)(*(u8***)(state + 0x240) + index);
    if (entry != 0)
        fn_8012BE64(entry + 0x6C, value);
}
