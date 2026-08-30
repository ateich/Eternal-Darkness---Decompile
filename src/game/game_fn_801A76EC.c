typedef unsigned char u8;
typedef struct { u8 pad[0x74]; float value; } Data;
void fn_801A76EC(Data* data, float value) { data->value = value; }
