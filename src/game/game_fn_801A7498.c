typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 pad[0x9C]; u32 value; } Data;
u32 fn_801A7498(Data* data) { return data->value; }
