int fn_8011FCB0(void* object)
{
    int result = 0;
    if (*(void**)((char*)object + 0x284) &&
        *(void**)((char*)object + 0x288) &&
        *(void**)((char*)object + 0x28C)) {
        result = 1;
    }
    return result;
}
