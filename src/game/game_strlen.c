unsigned long strlen(const char* string)
{
    const unsigned char* p = (const unsigned char*)string - 1;
    unsigned long length = -1;

    do {
        ++length;
    } while (*++p != 0);
    return length;
}
