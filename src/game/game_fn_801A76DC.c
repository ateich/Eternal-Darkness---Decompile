typedef unsigned char u8;
typedef struct { u8 pad[0x6C]; float value; } Data;
float fn_801A76DC(Data* data) { return data->value; }
