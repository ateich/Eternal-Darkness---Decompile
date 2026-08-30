typedef unsigned char u8;
typedef short s16;
typedef struct { u8 pad[0xBE]; s16 value; } Data;
s16 fn_801A76D4(Data* data) { return data->value; }
