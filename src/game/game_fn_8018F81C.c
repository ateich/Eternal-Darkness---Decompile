typedef unsigned char u8;

void fn_8018F81C(u8* descriptor, u8 count)
{
    float scale = 2.0f;

    if (count > 2) {
        scale = 64.0f / count;
    }

    descriptor[0] = count + 1;
    *(float*)(descriptor + 0x40) = scale;
}
