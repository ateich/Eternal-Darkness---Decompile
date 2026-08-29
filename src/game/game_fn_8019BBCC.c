void fn_8019BBCC(unsigned char* object, unsigned int set, unsigned int clear)
{
    unsigned int* flags;

    if (object == 0) {
        return;
    }
    flags = (unsigned int*)(object + 0x9C);
    *flags &= ~clear;
    *flags |= set;
}
