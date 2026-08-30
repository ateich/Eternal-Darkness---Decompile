typedef unsigned short u16;

typedef struct {
    unsigned char pad[0x68];
    void* object;
    unsigned char pad6C[0x40];
    u16 value;
} Data;

extern void* fn_80157CB8(void*, u16);

void* fn_801A78C0(Data* data) { return fn_80157CB8(data->object, data->value); }
