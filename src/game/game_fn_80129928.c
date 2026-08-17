typedef unsigned char u8;
typedef struct Vec { int x, y, z; } Vec;

extern u8* fn_80128E30(void*);

int fn_80129928(void* owner, Vec* position)
{
    int result = 0;
    u8* entry = fn_80128E30(owner);
    if ((*(unsigned short*)(entry + 0xF8) & 1) != 0) {
        result = 1;
        *(Vec*)(entry + 0xCC) = *position;
    }
    return result;
}
