typedef unsigned char u8;
typedef struct Vec { int x, y, z; } Vec;

void fn_801299DC(u8* entry, Vec* position)
{
    *(unsigned short*)(entry + 0xF8) = 1;
    *(Vec*)(entry + 0xCC) = *position;
}
