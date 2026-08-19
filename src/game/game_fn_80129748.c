typedef unsigned char u8;

#define FN_80128E30_RETURN u8*
#define FN_80128E30_PARAMETERS void*
extern FN_80128E30_RETURN fn_80128E30(FN_80128E30_PARAMETERS);

int fn_80129748(void* owner)
{
    return *(int*)(fn_80128E30(owner) + 0xC8);
}
