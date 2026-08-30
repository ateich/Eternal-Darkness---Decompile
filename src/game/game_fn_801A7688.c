typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 words[3]; } Value;
typedef struct { u8 pad[0x18]; Value values[1]; } Data;
int fn_801A7688(Data* data, int index, Value* out) { *out = data->values[index]; return 1; }
