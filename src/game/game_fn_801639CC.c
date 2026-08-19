unsigned int fn_801639CC(unsigned int value)
{
    unsigned int size = 4;

    while (size <= value) {
        size <<= 1;
    }
    return size;
}
