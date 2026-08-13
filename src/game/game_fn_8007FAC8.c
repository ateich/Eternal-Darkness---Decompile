typedef unsigned short u16;
typedef unsigned int u32;

extern void *fn_8015C28C(int);

int fn_8007FAC8(u32 value)
{
    unsigned char *state = fn_8015C28C(2);
    unsigned char *entry;
    u16 count = *(u16 *)(state + 0xB0);
    int i;

    for (i = 0; i < count; i++) {
        entry = *(unsigned char **)(state + 0xB4) + i * 0x74;
        if (value == *(u32 *)(entry + 0x2C) && (*(u32 *)(entry + 0x68) & 1) != 0) {
            return 1;
        }
    }
    return 0;
}
