typedef unsigned char u8;
typedef unsigned int u32;

extern void fn_801AC980(void*, int);

void fn_801914D8(u8* object)
{
    u32 zero;
    u8* entry;
    int count;
    int i;
    u8* flags = object + 0x8C;

    if ((flags[0] & 8) != 0) {
        count = object[1];
        if ((u32)count <= 7) {
            entry = flags;
            zero = 0;
            for (i = 0; i < count; i++) {
                void* handle = *(void**)(entry + 0x10);
                if (handle != 0) {
                    fn_801AC980(handle, 0x7F);
                    *(u32*)(entry + 0x10) = zero;
                }
                entry += 4;
            }
        }
    }
}
