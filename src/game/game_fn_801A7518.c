typedef unsigned char u8;
typedef signed short s16;
typedef struct { u8 pad[0xB4]; s16 value; } Data;
void fn_801A7518(Data* data, s16 value) { data->value = value; }
