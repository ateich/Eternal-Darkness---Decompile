typedef unsigned char u8;

extern u8 fn_80128EE4(void*);

int fn_80129228(void* owner)
{
    return (fn_80128EE4(owner) & 0xF) != 0;
}
