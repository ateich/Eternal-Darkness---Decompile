void fn_80139E04(unsigned char* object, int value, int size, int data, unsigned short type)
{
    *(int*)(object + 0x284) = value;
    *(int*)(object + 0x288) = size;
    *(int*)(object + 0x28C) = data;
    *(unsigned short*)(object + 0x2D6) = type;
}
