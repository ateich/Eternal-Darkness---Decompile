typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 pad[0xC4]; u16 value; } Data;
u16 fn_801A7580(Data* data) { return data->value; }
