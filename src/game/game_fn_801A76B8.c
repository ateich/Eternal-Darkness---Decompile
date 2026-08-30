typedef unsigned char u8;
typedef struct { u8 pad[0xC8]; u8 value; } Data;
unsigned int fn_801A76B8(Data* data) { return data->value; }
