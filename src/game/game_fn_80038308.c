typedef signed short s16;
typedef unsigned int u32;

typedef struct ObjectInfo {
    unsigned char pad[0x8C];
    void* data;
} ObjectInfo;

typedef struct ObjectData {
    unsigned char pad[0xE2];
    s16 channel1;
    s16 channel2;
    s16 channel3;
} ObjectData;
extern void *fn_80201B8C();
extern int fn_80201EF4(void*, s16*);
extern u32 fn_8020216C(void*);
extern int fn_80038464(void*, int, s16*);

int fn_80038308(void* object, int channel, s16* value)
{
    ObjectInfo* info;
    s16 current = 100;

    if (object != 0) {
        info = fn_80201B8C(object);
        if (info != 0 && info->data != 0) {
            switch (channel) {
            case 0:
                return fn_80201EF4(object, value);
            case 1:
                fn_80038464(object, 1, &current);
                *value = (fn_8020216C(object) & 0x1000)
                             ? current
                             : ((ObjectData*)info->data)->channel1;
                return 1;
            case 2:
                fn_80038464(object, 2, &current);
                *value = (fn_8020216C(object) & 0x2000)
                             ? current
                             : ((ObjectData*)info->data)->channel2;
                return 1;
            case 3:
                fn_80038464(object, 3, &current);
                *value = (fn_8020216C(object) & 0x20000)
                             ? current
                             : ((ObjectData*)info->data)->channel3;
                return 1;
            }
        }
    }
    return 0;
}
