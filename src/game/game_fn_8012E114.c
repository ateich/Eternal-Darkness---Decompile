typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void fn_80125ECC(void *);
extern void fn_8012BE18(const void*, void*, int);

int fn_8012E114(u8* owner, u32 index, void* output)
{
    int result = 0;
    u8* entry;

    fn_80125ECC(owner);
    entry = (*(u8***)(owner + 0x240))[index];
    if (entry != 0 && (*(u16*)(entry + 0xA) & 0x24) != 0) {
        fn_8012BE18(entry + 0x3C, output, 8);
        result = 1;
    }
    return result;
}
