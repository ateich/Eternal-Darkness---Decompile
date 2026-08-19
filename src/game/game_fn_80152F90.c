typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Vec3f {
    float x, y, z;
} Vec3f;

extern void fn_8019D66C(void);
extern void* fn_80148008(Vec3f*, void*, void*, void (*)(void));
extern void *fn_80156938();
extern void fn_80180374(void*, u8);
extern void fn_8017FF1C(void*, int);
extern void* fn_8015E780(void);
extern void fn_8019DF98(void*, void*);

void* fn_80152F90(Vec3f* position, void* arg1, u8* config, u8 kind)
{
    Vec3f copy = *position;
    void* result;
    u8* object;

    result = fn_80148008(&copy, arg1, config, fn_8019D66C);
    if (result != 0) {
        object = fn_80156938(result);
        if (object != 0) {
            fn_80180374(object, kind);
            fn_8017FF1C(object, 0x84);
            if (config != 0 && config[0x23] != 0)
                fn_8019DF98(object, fn_8015E780());
        }
    }
    return result;
}
