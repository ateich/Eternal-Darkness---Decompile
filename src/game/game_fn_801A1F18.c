typedef unsigned char u8;
typedef unsigned short u16;

extern float lbl_80650D1C;
extern double lbl_80650D20;

void fn_801A1F18(u8* object, u8* config)
{
    *(u16*)(object + 0x8C) = 0;
    *(u16*)(object + 0x8E) = 0;
    object[0xBD] = 0;
    *(float*)(object + 0x90) = *(float*)(config + 0x14);
    object[0xBC] = config[0x18];

    if (config[0x19] != 0) {
        *(float*)(object + 0x94) = lbl_80650D1C;
        *(float*)(object + 0x98) =
            *(float*)(object + 0x90) / config[0x19];
    } else {
        *(float*)(object + 0x94) = *(float*)(object + 0x90);
    }
}
