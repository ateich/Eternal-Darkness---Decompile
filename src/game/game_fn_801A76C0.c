typedef unsigned char u8;
typedef short s16;
typedef struct { u8 pad[0xB0]; s16 x; s16 y; } Data;
void fn_801A76C0(Data* data, s16* x, s16* y) { *x = data->x; *y = data->y; }
