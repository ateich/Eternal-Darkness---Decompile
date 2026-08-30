typedef unsigned short u16;

typedef struct {
    unsigned char pad[0x68];
    void* object;
    unsigned char pad6C[0x40];
    u16 mask;
} Data;

extern void* fn_80157CB8(void*, u16);
extern void* fn_80157E14(void*);

void* fn_801A7780(Data* data)
{
    return fn_80157E14(fn_80157CB8(data->object, data->mask));
}
