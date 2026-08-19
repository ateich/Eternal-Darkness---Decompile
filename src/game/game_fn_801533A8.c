typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3 {
    u32 x, y, z;
} Vec3;

extern void fn_80182B84(void*);
extern void fn_80182BCC(void);
extern void* fn_80148008(Vec3*, void*, void*, void (*)(void));
extern void *fn_80156938();
extern void fn_8017FF1C(void*, int);

void* fn_801533A8(Vec3* position, void* object, u8 kind, u8 mode,
                  u16 first, u16 second, u8 variant)
{
    Vec3 copy;
    u8 descriptor[0x90];
    void* result;

    fn_80182B84(descriptor);
    descriptor[0] = kind;
    descriptor[1] = mode;
    *(u16*)(descriptor + 6) = first;
    *(u16*)(descriptor + 8) = second;
    descriptor[2] = 0xFF;
    *(signed char*)(descriptor + 3) = -1;
    descriptor[0x15] = 20;
    descriptor[0x17] = variant;
    copy = *position;
    result = fn_80148008(&copy, object, descriptor, fn_80182BCC);
    if (result != 0) {
        fn_8017FF1C(fn_80156938(result), 4);
    }
    return result;
}
