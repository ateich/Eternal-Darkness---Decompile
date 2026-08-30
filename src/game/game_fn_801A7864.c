typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    unsigned char pad[0x68];
    void* object;
    unsigned char pad6C[0x40];
    u16 value;
} Data;

extern u32 fn_80157C80(void*);

void fn_801A7864(Data* data)
{
    u32 flags;
    data->value = 1;
    flags = fn_80157C80(data->object);
    if (flags & 0x80) {
        data->value = 0x80;
    } else if (flags & 0x20) {
        data->value = 0x40;
    }
}
