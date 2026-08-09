typedef unsigned long u32;

extern u32 fn_80036D5C(void*);

u32 fn_80036DF0(void* object)
{
    return fn_80036D5C(object) & 4;
}
