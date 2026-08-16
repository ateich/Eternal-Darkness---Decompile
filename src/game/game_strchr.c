char* strchr(const char* string, int value)
{
    const unsigned char* p = (const unsigned char*)string - 1;
    unsigned int ch = (unsigned char)value;
    unsigned int current;

    while ((current = *++p) != 0) {
        if (current == ch) {
            return (char*)p;
        }
    }
    if (ch == 0) {
        return (char*)p;
    }
    return 0;
}
