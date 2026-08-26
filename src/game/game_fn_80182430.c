typedef unsigned char u8;

void fn_80182430(u8* object, u8 value)
{
    if (object != 0) {
        object[0x92] = value;
    }
}
