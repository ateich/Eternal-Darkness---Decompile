typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;

void fn_80181808(unsigned char* object, int index, s16 limit)
{
    u16* entry = (u16*)(object + index * 2);
    entry[7] -= (s8)object[1];
    if (entry[7] < limit) {
        entry[7] = limit;
    }
}
