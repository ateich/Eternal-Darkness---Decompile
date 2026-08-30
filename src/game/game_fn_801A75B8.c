typedef unsigned char u8;
typedef struct { u8 pad[0x6C]; float value; } Data;
void fn_801A75B8(Data* data, float value) { data->value = value; }
