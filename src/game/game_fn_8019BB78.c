typedef signed short s16;

void fn_8019BB78(unsigned char* object, s16* values)
{
    if (object != 0) {
        *(s16*)(object + 0xA4) = values[0];
        *(s16*)(object + 0xA6) = values[1];
        *(s16*)(object + 0xA8) = values[2];
    }
}
