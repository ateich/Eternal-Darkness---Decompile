typedef signed short s16;
typedef unsigned char u8;

s16 fn_8019DD64(u8* object)
{
    int count = object[1];
    s16 result = 0;
    s16 selected;
    s16* values = (s16*)(object + 0x8C);

    while (count-- > 0) {
        s16 value = values[6];
        if (value < 0) {
            selected = result;
            if (value < result) {
                selected = value;
            }
            if (selected != result) {
                result = selected;
            }
        }
        values++;
    }
    return result;
}
