typedef unsigned char u8;

unsigned short fn_8011F134(void* object)
{
    void* owner = *(void**)((u8*)object + 60);
    return *(unsigned short*)((u8*)owner + 34);
}
