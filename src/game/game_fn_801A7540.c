typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 pad[0x8C]; u32 value; } Data;
u32 fn_801A7540(Data* data) { return data->value; }
