typedef unsigned char u8;

extern u8* fn_80128E30(void*);

int fn_80129748(void* owner)
{
    return *(int*)(fn_80128E30(owner) + 0xC8);
}
