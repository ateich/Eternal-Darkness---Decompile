void fn_8011FAFC(void* object, int enabled)
{
    unsigned int* flags = (unsigned int*)((char*)object + 0x254);
    if (enabled) {
        *flags &= ~(1U << 9);
    } else {
        *flags |= 1U << 9;
    }
}
