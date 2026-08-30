typedef unsigned char u8;
typedef struct { u8 pad[0x68]; void* value; } Data;

void* fn_801A7778(Data* data) { return data->value; }
