typedef unsigned char u8;

typedef struct ObjectInfo {
    u8 pad00[0x8C];
    void* resources;
} ObjectInfo;

extern void* fn_80201B8C();

void* fn_80036D38(void* object)
{
    return ((ObjectInfo*)fn_80201B8C(object))->resources;
}
