extern void* memset(void* destination, int value, unsigned int size);

void fn_80137DD4(void* entry)
{
    if (entry != 0) {
        memset(entry, 0, 28);
    }
}
