typedef signed short s16;

typedef struct Object {
    void* primary;
    unsigned char* secondary;
} Object;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

void fn_80157C0C(Object* object, Vec3* out)
{
    out->x = (float)*(s16*)(object->secondary + 0x2c);
    out->y = (float)*(s16*)(object->secondary + 0x2e);
    out->z = (float)*(s16*)(object->secondary + 0x30);
}
