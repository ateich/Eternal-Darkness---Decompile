typedef unsigned char u8;
typedef int s32;

typedef struct ObjectInfo {
    u8 pad00[0x9E];
    u8 value;
} ObjectInfo;

extern void* fn_80201B8C();

s32 fn_80036E14(void* object)
{
    ObjectInfo* info;

    if (object != 0) {
        info = fn_80201B8C(object);
        if (info != 0) {
            return info->value;
        }
    }
    return -1;
}
