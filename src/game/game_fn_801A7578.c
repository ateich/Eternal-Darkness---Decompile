typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 pad[0xC2]; u16 value; } Data;
u16 fn_801A7578(Data* data) { return data->value; }
