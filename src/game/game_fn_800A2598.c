typedef unsigned char u8;

typedef struct Object800A2598 {
    u8 pad000[0x68];
    void* resource;
} Object800A2598;

extern void fn_801D0CF0(void*);

void fn_800A2598(Object800A2598* object)
{
    if (object->resource != 0) {
        fn_801D0CF0(object->resource);
        object->resource = 0;
    }
}
