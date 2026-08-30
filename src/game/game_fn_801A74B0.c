typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 pad[0xA0]; u32 value; } Data;
void fn_801A74B0(Data* data, u32 value) { data->value = value; }
