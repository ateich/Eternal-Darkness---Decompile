typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

extern u32 fn_801F6D90(s16, s16, s16);
extern void fn_8018A88C(void*);

void fn_8019D50C(u8* object)
{
    u32 distance = fn_801F6D90(*(s16*)(object + 0x10),
                               *(s16*)(object + 0x12),
                               *(s16*)(object + 0x14));

    if (object[0x102] == 0 && distance > 100) {
        fn_8018A88C(object);
    }
}
