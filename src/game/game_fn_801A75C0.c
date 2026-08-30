typedef unsigned int u32;

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Vec3;

typedef struct {
    unsigned char pad[0x18];
    Vec3 values[1];
} Data;

Vec3 fn_801A75C0(Data* data, int index, Vec3* value)
{
    Vec3 old = data->values[index];
    data->values[index] = *value;
    return old;
}
