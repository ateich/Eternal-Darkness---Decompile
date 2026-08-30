typedef unsigned char u8;
typedef struct { u8 pad[0xCC]; u8 value; } Data;

u8 fn_801A7768(Data* data) { return data->value; }
