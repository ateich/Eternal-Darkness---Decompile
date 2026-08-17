extern void fn_8011FB54(void* object, void* value);

void* fn_8011F9F8(void* object)
{
    void* other = *(void**)((char*)object + 0x174);
    if (other != 0 && object != other) {
        fn_8011FB54(object, *(void**)((char*)other + 0x250));
    }
    return *(void**)((char*)object + 0x250);
}
