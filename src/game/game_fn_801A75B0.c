typedef unsigned char u8;
typedef struct { u8 pad[0xC8]; u8 value; } Data;
void fn_801A75B0(Data* data, u8 value) { data->value = value; }
