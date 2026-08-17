void* fn_8011FB5C(void* object, void* value)
{
    void* old = *(void**)((char*)object + 0x258);
    *(void**)((char*)object + 0x258) = value;
    return old;
}
