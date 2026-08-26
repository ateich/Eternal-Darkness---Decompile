typedef unsigned char u8;

void* fn_801809A0(u8* entry)
{
    void* result = 0;
    if (entry != 0) {
        result = *(void**)(entry + 0x34);
    }
    return result;
}
