typedef unsigned char u8;

void* fn_801296E8(u8* entry, void* value)
{
    void* old = *(void**)(entry + 0xC8);
    *(void**)(entry + 0xC8) = value;
    return old;
}
