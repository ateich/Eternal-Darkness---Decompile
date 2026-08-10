typedef unsigned char u8;

typedef struct ResourceState {
    void* value;
} ResourceState;

typedef struct ObjectInfo {
    u8 pad00[0x8C];
    ResourceState* resources;
} ObjectInfo;

extern void* fn_80201B8C();

void fn_80036DA4(void* object, register void* value)
{
    ObjectInfo* info;

    if (object != 0) {
        info = fn_80201B8C(object);
        if (info != 0 && info->resources != 0) {
            info->resources->value = value;
        }
    }
}
