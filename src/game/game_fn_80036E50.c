typedef unsigned char u8;
typedef int s32;

typedef struct ObjectInfo {
    u8 pad00[0x9F];
    u8 value;
} ObjectInfo;

extern ObjectInfo* fn_80201B8C(void*);

s32 fn_80036E50(void* object)
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
