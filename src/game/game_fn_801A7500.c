typedef unsigned char u8;
typedef signed short s16;
typedef struct { u8 pad[0xB8]; s16 value; } Data;
s16 fn_801A7500(Data* data) { return data->value; }
