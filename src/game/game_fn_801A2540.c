typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;

extern int lbl_8064D18C;

int fn_801A2540(u8* object)
{
    float current = *(float*)(object + 0x94);
    u8* particle = *(u8**)(object + 0x4C);

    if (current < *(float*)(object + 0x90)) {
        *(float*)(object + 0x94) = current + *(float*)(object + 0x98);
        if (*(float*)(object + 0x94) > *(float*)(object + 0x90)) {
            *(float*)(object + 0x94) = *(float*)(object + 0x90);
        }
    } else if (current > *(float*)(object + 0x90)) {
        *(float*)(object + 0x94) = current - *(float*)(object + 0x98);
        if (*(float*)(object + 0x94) < *(float*)(object + 0x90)) {
            *(float*)(object + 0x94) = *(float*)(object + 0x90);
        }
    }

    *(s16*)(particle + 0xA) = *(s16*)(object + 0x10);
    *(s16*)(particle + 0xC) = *(s16*)(object + 0x12);
    *(s16*)(particle + 0xE) = *(s16*)(object + 0x14);

    if (*(u16*)(object + 0xC) != 0 &&
        *(u16*)(object + 0xA) >= *(u16*)(object + 0xC)) {
        *(u16*)(object + 0x22) = 8;
    }
    if (object[0xBC] != 0 && lbl_8064D18C != *(int*)(object + 0x38)) {
        *(u16*)(object + 0x22) = 8;
    }
    (*(u16*)(object + 0xA))++;
    return 0;
}
