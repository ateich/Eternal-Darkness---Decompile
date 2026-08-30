typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 words[3]; } Value;
typedef struct { u8 pad[0x54]; Value value; } Data;
void fn_801A764C(Data* data, const Value* value) { data->value = *value; }
