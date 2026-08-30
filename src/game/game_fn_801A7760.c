typedef unsigned char u8;
typedef struct { u8 pad[0x60]; void* value; } Data;

void* fn_801A7760(Data* data) { return data->value; }
