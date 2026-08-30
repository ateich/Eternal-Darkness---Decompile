typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 pad[0xC2]; u16 value; } Data;
void fn_801A7598(Data* data, u16 value) { data->value = value; }
