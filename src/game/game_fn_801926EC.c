typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern s32 lbl_8064D18C;
extern void fn_801929A4(void);
extern void* fn_80201814(void*);
extern s32 fn_800FBFB0(void);
extern void fn_8014D478(s32, float*, float*, s32, s32, u8*, s32);

s32 fn_801926EC(u8* object)
{
    u8 colour[4];
    float position[3];
    float offset[3];
    u8* entry;
    s32 count;
    s32 i;

    if (*(s32*)(object + 0x38) != lbl_8064D18C ||
        fn_80201814(*(void**)(object + 0xC8)) == 0 ||
        **(s32***)(object + 0xD8) != 0) {
        *(u16*)(object + 0x22) = 8;
    } else if (*(s32*)(object + 0xB8) != 0) {
        *(void (**)(void))(object + 0x14C) = fn_801929A4;
        entry = *(u8**)(object + 0x4C);
        count = object[1] >> 1;
        for (i = 0; i < count; i++, entry += 0x38)
            *(u16*)(entry + 8) = *(u16*)(object + 0xA);
        for (; i < object[1]; i++, entry += 0x38)
            *(u16*)(entry + 8) = (u16)(count + *(u16*)(object + 0xA));

        if (*(s32*)(object + 0xBC) != 0) {
            *(s32*)colour = *(s32*)(object + 0xDC);
            position[0] = *(s16*)(object + 0x10);
            position[1] = *(s16*)(object + 0x12);
            position[2] = *(s16*)(object + 0x14);
            offset[0] = *(s16*)(object + 0xC0) - *(s16*)(object + 0x10);
            offset[1] = *(s16*)(object + 0xC2) - *(s16*)(object + 0x12);
            offset[2] = *(s16*)(object + 0xC4) - *(s16*)(object + 0x14) + 100;
            switch (object[0xB6]) {
            case 1: colour[0] -= fn_800FBFB0() & 0x1F; break;
            case 2: colour[1] -= fn_800FBFB0() & 0x1F; break;
            case 3: colour[2] -= fn_800FBFB0() & 0x1F; break;
            }
            fn_8014D478(0, position, offset, 0, 1, colour, 5);
        }
    }
    (*(u16*)(object + 0xA))++;
    return 0;
}
