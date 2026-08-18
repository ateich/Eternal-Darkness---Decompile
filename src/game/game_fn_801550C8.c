typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_80155158(void* work);
extern void* fn_80149D98(void (*callback)(void*));
extern void fn_80149D64(void* work);
extern void* memcpy(void* dest, const void* src, unsigned int size);
extern unsigned int fn_8015E780(void);

void fn_801550C8(void* source, u8 flag)
{
    void* work;
    char* data;

    work = fn_80149D98(fn_80155158);
    if (work != 0) {
        *(u8*)((char*)work + 0x1328) = 0x84;
        fn_80149D64(work);
        data = (char*)work + 8;
        memcpy(data, source, 0x90);
        *(u8*)(data + 0xBA) = 0;
        *(u8*)(data + 0xBB) = flag;
        *(unsigned int*)(data + 0xB0) = fn_8015E780();
        *(u16*)(data + 0xB6) = 0;
        *(u16*)(data + 0xB8) = 0;
    }
}
