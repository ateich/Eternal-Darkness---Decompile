typedef unsigned char u8;
typedef unsigned short u16;
typedef struct ResourceData { u8 pad[6]; u16 count; u16* values; } ResourceData;
typedef struct Resource { u8 pad[4]; ResourceData* data; } Resource;
typedef struct Object { u8 pad[0x240]; Resource** resources; } Object;
extern void fn_80125ECC(void *);
int fn_80130670(Object* object, int id, int index)
{
    int result = 0;
    int i;
    Resource* resource;

    fn_80125ECC(object);
    resource = object->resources[index];
    if (resource != 0) {
        for (i = 0; i < resource->data->count; i++) {
            u16 value = resource->data->values[i];
            if ((value & 0x8000) != 0 && id == (value & ~0x8000)) {
                result = 1;
            }
        }
    }
    return result;
}
