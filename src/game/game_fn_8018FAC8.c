typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

extern void* memcpy(void*, const void*, unsigned int);
extern void fn_80185F10(void*, void*, u16, void*);

void fn_8018FAC8(u8* object, u8* descriptor)
{
    u8* state = object + 0xA0;

    object[0x8C] = descriptor[0x20];
    *(u16*)(object + 0xA6) = *(u16*)(descriptor + 0x30);
    object[0xA1] = descriptor[0x28];
    object[0xA0] = 0;
    *(float*)(object + 0xD0) = *(float*)(descriptor + 0x40);
    object[0xA2] = descriptor[0x29];
    memcpy(state + 0x34, object + 0x10, 6);

    if (*(s8*)(state + 1) != 0) {
        fn_80185F10(state, object, 0, object + 0x10);
    } else {
        fn_80185F10(state, object, *(u16*)(state + 6), object + 0x10);
    }
}
