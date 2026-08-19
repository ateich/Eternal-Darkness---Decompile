typedef unsigned char u8;
typedef struct Vec { int x, y, z; } Vec;

#define FN_80128E30_RETURN u8*
#define FN_80128E30_PARAMETERS void*
extern FN_80128E30_RETURN fn_80128E30(FN_80128E30_PARAMETERS);

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
