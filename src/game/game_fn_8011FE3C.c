void* fn_8011FE3C(void* object, void* value)
{
    void* previous = *(void**)((char*)object + 0x174);
    *(void**)((char*)object + 0x174) = value;
    return previous;
}
