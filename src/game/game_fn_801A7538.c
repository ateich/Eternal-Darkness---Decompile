typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 pad[0xB6]; u16 value; } Data;
void fn_801A7538(Data* data, u16 value) { data->value = value; }
