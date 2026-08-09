typedef unsigned char u8;

typedef struct ObjectInfo {
    u8 pad00[0x8C];
    void* resources;
} ObjectInfo;

extern ObjectInfo* fn_80201B8C(void*);

void* fn_80036D38(void* object)
{
    return fn_80201B8C(object)->resources;
}
