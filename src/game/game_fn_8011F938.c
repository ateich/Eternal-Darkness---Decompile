void* fn_8011F938(void* object, void* value)
{
    void* old = *(void**)((char*)object + 0x3C);
    *(void**)((char*)object + 0x3C) = value;
    return old;
}
