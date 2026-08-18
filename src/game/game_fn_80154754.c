extern void* fn_80149D98(void (*callback)(void*));
extern void fn_80149D64(void* work);

extern void fn_801547CC(void* work);

void fn_80154754(void* object, unsigned char index)
{
    void* work;

    if (object != 0) {
        work = fn_80149D98(fn_801547CC);
        if (work != 0) {
            *(unsigned char*)((char*)work + 0x1328) = 0x84;
            fn_80149D64(work);
            *(void**)((char*)work + 8) = object;
            *(unsigned char*)((char*)work + 0xD) = index;
            *(unsigned char*)((char*)work + 0xE) = 9;
            *(unsigned char*)((char*)work + 0xF) = 0;
        }
    }
}
