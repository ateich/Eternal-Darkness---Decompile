typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 pad[0x80]; u32 value; } Data;
u32 fn_801A7590(Data* data) { return data->value; }
