typedef unsigned char u8;
typedef struct { u8 pad[0xC9]; u8 value; } Data;
void fn_801A75A8(Data* data, u8 value) { data->value = value; }
