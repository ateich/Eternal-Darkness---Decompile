typedef unsigned char u8;
typedef signed short s16;
typedef unsigned long u32;

extern const float lbl_80650D44;

void fn_801A3D18(u8* object, u8* descriptor)
{
    u8* state = object + 0x8C;
    int i;

    *(s16*)(object + 0xAE) = *(s16*)(descriptor + 0x36);
    *(float*)(object + 0xB0) = lbl_80650D44;
    *(float*)(object + 0xB4) = *(float*)(descriptor + 0x30);
    state[0xD] = descriptor[0x38];
    state[0xE] = descriptor[0x39];
    state[0xF] = descriptor[0x3A];
    state[0x10] = descriptor[0x3B];
    state[0x11] = descriptor[0x3D];
    if (descriptor[0x3D] == 0)
        state[0x13] = descriptor[0];
    else
        state[0x13] = 0;
    state[0x12] = 0;
    state[0xC] = descriptor[0x41] | 1;
    state[0x14] = 0;
    for (i = 0; i < descriptor[0]; i++)
        state[i + 0x17] = descriptor[0x38];
    state[0x16] = descriptor[0x3F];
    state[0x15] = descriptor[0x3E];
    state[0x1F] = 0;
    state[0x20] = 0;
    *(u32*)(state + 4) = *(u32*)(descriptor + 0x18);
    *(u32*)(state + 8) = *(u32*)(descriptor + 0x1C);
    *(u32*)state = *(u32*)(descriptor + 0x14);
    state[0x1E] = descriptor[0x40];
}
