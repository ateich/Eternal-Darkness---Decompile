extern void* fn_80149D98(void (*callback)(void*));
extern void fn_80149D64(void* work);
extern void* fn_80201890(void* object);

extern void fn_801545E4(void* work);

void fn_80154570(void* object)
{
    void* work;
    void* value;

    work = fn_80149D98(fn_801545E4);
    if (work != 0) {
        value = fn_80201890(object);
        *(unsigned char*)((char*)work + 0x1328) = 0x84;
        fn_80149D64(work);
        *(void**)((char*)work + 8) = value;
        *(unsigned char*)((char*)work + 0xE) = 0xE;
        *(unsigned char*)((char*)work + 0xF) = 0;
    }
}
