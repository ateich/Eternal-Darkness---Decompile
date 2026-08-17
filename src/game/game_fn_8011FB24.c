int fn_8011FB24(void* object)
{
    int result = 1;
    if (*(unsigned int*)((char*)object + 0x254) & 0x200U) {
        result = 0;
    }
    return result;
}
