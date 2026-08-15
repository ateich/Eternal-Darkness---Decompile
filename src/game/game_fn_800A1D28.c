typedef struct Object800A1D28 {
    unsigned char pad00[0x64];
    void* value;
} Object800A1D28;

extern Object800A1D28* fn_80201B8C();

void* fn_800A1D28(void)
{
    return fn_80201B8C()->value;
}
