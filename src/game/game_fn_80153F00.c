typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3f {
    float x, y, z;
} Vec3f;

typedef struct Descriptor {
    u8 data[0x90];
} Descriptor;

extern void fn_80183DD4(Descriptor*);
extern void fn_80183EE0(void);
extern void* fn_80148008(Vec3f*, void*, Descriptor*, void (*)(void));
extern void* fn_80156938(void*);
extern void fn_8017FF1C(void*, int);

void fn_80153F00(u8 style, u8 mode, u8 kind, u8 type, u32* color,
                 u16 value, Vec3f* position, void* resource, u8 first,
                 u8 second, u16 count)
{
    Descriptor descriptor;
    Vec3f copy;
    void* result;

    fn_80183DD4(&descriptor);
    *(u16*)(descriptor.data + 6) = value;
    *(u16*)(descriptor.data + 8) = value;
    descriptor.data[0x18] = second;
    descriptor.data[0x19] = first;
    *(u16*)(descriptor.data + 0x1A) = count;
    *(u32*)(descriptor.data + 0x1C) = *color;
    descriptor.data[0x17] = 1;
    descriptor.data[0x14] = kind;
    descriptor.data[0x15] = style;
    descriptor.data[0] = type;
    descriptor.data[1] = mode;
    copy = *position;
    result = fn_80148008(&copy, resource, &descriptor, fn_80183EE0);
    if (result != 0)
        fn_8017FF1C(fn_80156938(result), 4);
}
