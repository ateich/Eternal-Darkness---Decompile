typedef unsigned char u8;
typedef unsigned short u16;

extern void* fn_8015C910(void);

void fn_8018EA58(u8* object)
{
    if (fn_8015C910() != 0 && *(u16*)(object + 0xC) != 0) {
        (*(u16*)(object + 0xC))++;
        if (*(u16*)(object + 0xC) == 0xFFFF && *(u16*)(object + 0xA) != 0) {
            *(u16*)(object + 0xC) -= *(u16*)(object + 0xA);
            *(u16*)(object + 0xA) = 0;
            *(unsigned int*)(object + 0x44) = 0;
        }
    }
}
