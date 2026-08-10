typedef signed short s16;
typedef unsigned char u8;

typedef struct ObjectInfo {
    u8 pad[0x8C];
    void* data;
    u8 pad_90[0xE];
    u8 type;
} ObjectInfo;

typedef struct ObjectData {
    u8 pad[0xEA];
    s16 current[15];
    s16 limit[15];
    s16 base[15];
} ObjectData;

extern void* fn_80201814();
extern void* fn_80201B8C();

int fn_800387FC(int id, int index, s16 value)
{
    void* object;
    ObjectInfo* info;
    u8* data;
    int result;

    object = fn_80201814(id);
    result = 0;
    if (object != 0) {
        info = fn_80201B8C(object);
        if (info != 0 && info->type == 2) {
            data = (u8*)info->data;
            data += index * 2;
            result = 1;
            ((ObjectData*)data)->base[0] = value;
        }
    }
    return result;
}
