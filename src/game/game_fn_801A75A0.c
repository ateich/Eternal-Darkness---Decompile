typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 pad[0xC4]; u16 value; } Data;
void fn_801A75A0(Data* data, u16 value) { data->value = value; }
