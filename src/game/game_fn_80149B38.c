void fn_80149B38(unsigned char* list)
{
    unsigned char* current;
    int i;

    i = 0;
    current = list;
    while (i < list[0]) {
        *(int*)(current + 8) = i;
        current += 4;
        i++;
    }
}
