typedef int s32;

typedef struct ObjectInfo {
    unsigned char pad_00[0x94];
    s32 value94;
} ObjectInfo;

extern void* fn_80201B8C();

s32 fn_80035628(void* object)
{
    ObjectInfo* info = fn_80201B8C(object);

    if (info != 0) {
        return info->value94;
    }
    return 0;
}
