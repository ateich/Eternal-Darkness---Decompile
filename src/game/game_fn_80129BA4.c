typedef unsigned char u8;

extern float fn_80179F20(u8*, float);

void fn_80129BA4(u8* entry, float value, float scale)
{
    *(unsigned short*)(entry + 0xF8) |= 2;
    *(float*)(entry + 0xBC) = scale;
    *(float*)(entry + 0xC0) = fn_80179F20(entry, value);
}
