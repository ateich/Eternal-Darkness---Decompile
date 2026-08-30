typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 pad[0xA8]; u32 value; } Data;
u32 fn_801A7560(Data* data, u32 value) { u32 old = data->value; data->value = value; return old; }
