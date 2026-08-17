void fn_8011F7E0(void* object, int enabled)
{
    /* Honest reconstruction; MWCC's retail clear uses one rlwinm. */
    unsigned int* flags = (unsigned int*)((char*)object + 0x254);
    if (enabled) {
        *flags |= 0x400;
    } else {
        *flags &= ~0x400;
    }
}
