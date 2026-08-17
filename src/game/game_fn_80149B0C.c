void fn_80149B0C(unsigned char* list, void* first, void* second)
{
    unsigned char* current;
    int i;

    i = 0;
    current = list;
    while (i < list[0]) {
        *(void**)(current + 8) = first;
        i++;
        *(void**)(current + 0x48) = second;
        current += 4;
    }
}
