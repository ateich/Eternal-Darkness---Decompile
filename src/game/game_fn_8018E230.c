typedef unsigned char u8;
void fn_8018E230(u8* object, u8* alpha, u8 type, u8 value, u8 count, u8 stride)
{
    object[0] = type;
    alpha[0] = value;
    object[5] = count;
    object[1] = stride;
    object[7] = 0;
}
