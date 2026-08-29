typedef unsigned char u8;

void fn_8017FF14(u8* object, int value);
void fn_8017FD6C(u8* object);
void fn_801AC980(void* handle, int value);

void fn_801964E8(u8* object, int set, int cleanup)
{
    if (set) {
        object[0xa5] |= 0x20;
    } else if (cleanup) {
        object[0xa5] &= ~1;
        fn_8017FF14(object, 0);
        fn_8017FD6C(object);
        if (*(void**)(object + 0x90)) {
            fn_801AC980(*(void**)(object + 0x90), 1);
            *(void**)(object + 0x90) = 0;
        }
    } else {
        object[0xa5] &= ~0x20;
    }
}
