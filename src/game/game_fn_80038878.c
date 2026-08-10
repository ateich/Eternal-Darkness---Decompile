typedef signed short s16;
typedef unsigned char u8;

typedef struct ObjectInfo {
    u8 pad[0x8C];
    void* data;
    int resource_id;
    u8 pad_94[0xA];
    u8 type;
    u8 subtype;
} ObjectInfo;

typedef struct Resource {
    u8 pad[0x46];
    s16 values[3];
} Resource;

typedef struct LinkedData {
    u8 pad[0x10];
    float value;
} LinkedData;

typedef struct LinkedInfo {
    u8 pad[0x14];
    LinkedData* data;
} LinkedInfo;

extern void* fn_80201814();
extern void* fn_80201B8C();
extern Resource* fn_80072354(int);
extern double lbl_8064E210;
extern float lbl_8064E23C;

int fn_80038878(int id, int index, s16 value)
{
    void* object;
    ObjectInfo* info;
    Resource* resource;
    LinkedInfo* linked_info;
    int* linked_ids;
    int result;

    object = fn_80201814(id);
    result = 0;
    if (object != 0) {
        info = fn_80201B8C(object);
        if (info != 0) {
            if (info->type == 1 && info->subtype == 1) {
                if (info != 0 && info->resource_id != -1) {
                    resource = fn_80072354(info->resource_id);
                    switch (index) {
                    case 0:
                        ((s16*)((u8*)info->data + 0xE0))[0] = value;
                        result = 1;
                        break;
                    case 1:
                        resource->values[0] = value;
                        result = 1;
                        break;
                    case 2:
                        resource->values[1] = value;
                        result = 1;
                        break;
                    case 3:
                        resource->values[2] = value;
                        result = 1;
                        break;
                    }
                }
                if (info != 0 && result != 0 && index != 3) {
                    linked_ids = (int*)info->data;
                    linked_ids = (int*)((u8*)linked_ids + index * 4);
                    object = fn_80201814(linked_ids[1]);
                    if (object != 0) {
                        linked_info = (LinkedInfo*)fn_80201B8C(object);
                        linked_info->data->value = (float)value / lbl_8064E23C;
                    }
                }
            } else if (info->type == 2) {
                ((s16*)((u8*)info->data + 0xE0))[0] = value;
            }
        }
    }
    return result;
}
