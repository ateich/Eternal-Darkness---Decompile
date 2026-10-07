typedef struct ObjectData {
    unsigned char pad[0x70];
    float values[1];
} ObjectData;

typedef struct ObjectInfo {
    unsigned char pad[0x8C];
    ObjectData *data;
    unsigned char kind_pad[0x0F];
    unsigned char kind;
} ObjectInfo;

void fn_800C1B18(ObjectInfo *object, unsigned int index, float value)
{
    switch (object->kind) {
    case 1:
    case 3:
    case 4:
    case 5:
    case 7:
    case 10:
    case 11:
    case 12:
    case 21:
    case 24:
    case 38:
    case 39:
        object->data->values[index] = value;
        break;
    }
}
