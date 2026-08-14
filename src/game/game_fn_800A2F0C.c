typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Object800A2F0C {
    u8 pad000[0x24C];
    int handle;
} Object800A2F0C;

extern void* fn_80201814(int);
extern void fn_802020B4(void*, int);

void fn_800A2F0C(Object800A2F0C* object, int value)
{
    Object800A2F0C* current = object;
    u32 i = 0;
    do {
        if (current->handle != 0) {
            void* runtime = fn_80201814(current->handle);
            if (runtime != 0) {
                fn_802020B4(runtime, value);
            }
        }
        i++;
        current = (Object800A2F0C*)((u8*)current + 4);
    } while (i < 4);
}
