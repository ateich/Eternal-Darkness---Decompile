typedef unsigned char u8;

extern void* fn_80201B3C(void*);

u8 fn_8008CA28(void* object, void* owner)
{
    u8 equal = owner == fn_80201B3C(object);
    int result = 1;
    if (!equal)
        result = 0;
    return result;
}
