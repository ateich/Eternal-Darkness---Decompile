typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 pad[0xB6]; u16 value; } Data;
u16 fn_801A7530(Data* data) { return data->value; }
