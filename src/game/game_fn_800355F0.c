typedef int s32;

typedef struct ObjectInfo {
    unsigned char pad_00[0x94];
    s32 value94;
} ObjectInfo;

extern void* fn_80201B8C();

void fn_800355F0(void* object, s32 value)
{
    ObjectInfo* info = fn_80201B8C(object);

    if (info != 0) {
        info->value94 = value;
    }
}
