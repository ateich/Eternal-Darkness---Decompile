typedef unsigned char u8;
typedef struct { u8 pad[0xCC]; u8 value; } Data;
void fn_801A7670(Data* data, u8 value) { data->value = value; }
