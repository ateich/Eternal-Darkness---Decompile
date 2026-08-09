typedef signed short s16;

typedef struct ObjectInfo {
    unsigned char pad[0x8C];
    void* data;
    int resource_id;
} ObjectInfo;

typedef struct ObjectData {
    unsigned char pad[0xE0];
    s16 channel0;
} ObjectData;

typedef struct Resource {
    unsigned char pad[0x46];
    s16 channel1;
    s16 channel2;
    s16 channel3;
} Resource;

extern ObjectInfo* fn_80201B8C(void*);
extern Resource* fn_80072354(int);

int fn_80038464(void* object, int channel, s16* value)
{
    ObjectInfo* info;
    Resource* resource;

    if (object != 0) {
        info = fn_80201B8C(object);
        if (info != 0 && info->resource_id != -1) {
            resource = fn_80072354(info->resource_id);
            switch (channel) {
            case 0:
                *value = info->data != 0
                             ? ((ObjectData*)info->data)->channel0
                             : 0;
                return 1;
            case 1:
                *value = resource->channel1;
                return 1;
            case 2:
                *value = resource->channel2;
                return 1;
            case 3:
                *value = resource->channel3;
                return 1;
            }
        }
    }
    return 0;
}
