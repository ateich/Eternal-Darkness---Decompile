typedef unsigned char u8;

extern const float lbl_8065094C;

void fn_80180DDC(u8* object, u8 value)
{
    object[0x16] = value;
    *(float*)(object + 0x2C) = lbl_8065094C / (float)value;
}
