typedef unsigned char u8;
typedef unsigned int u32;

extern u8* fn_80156938(void*);
extern void* fn_8017FDA8(void*, int);
extern void fn_80149B60(void*, void*, u32, u32, int);

void fn_8014F53C(void* object, void* other)
{
    u8* other_runtime = fn_80156938(other);
    u8* runtime = fn_80156938(object);

    if (runtime != 0 && *(void**)(runtime + 0x88) != 0) {
        void* position = fn_8017FDA8(*(void**)(runtime + 0x88), 0);
        fn_80149B60(other_runtime, position, *(u32*)(runtime + 8),
                    *(u32*)(runtime + 0x48), 0);
    }
}
