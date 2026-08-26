typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;

void fn_8018183C(unsigned char* object, int index, s16 limit)
{
    u16* entry = (u16*)(object + index * 2);
    s8 amount = object[1];
    u16 value = entry[7];

    entry[7] = value + amount;
    if (entry[7] > limit) {
        entry[7] = limit;
    }
}
