void* memchr(const void* ptr, int value, unsigned long count)
{
    unsigned char byte = (unsigned char)value;
    const unsigned char* cursor = (const unsigned char*)ptr - 1;

    ++count;
    while (--count != 0) {
        if (*++cursor == byte) {
            return (void*)cursor;
        }
    }
    return 0;
}
