typedef unsigned char u8;
typedef signed short s16;
typedef struct { u8 pad[0xBA]; s16 value; } Data;
void fn_801A7528(Data* data, s16 value) { data->value = value; }
