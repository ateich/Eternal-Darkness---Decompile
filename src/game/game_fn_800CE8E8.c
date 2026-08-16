typedef unsigned char u8;
typedef signed short s16;

typedef struct Data {
    u8 pad[0xF2];
    s16 status;
} Data;

typedef struct RuntimeState {
    u8 pad[0x20];
    Data *data;
} RuntimeState;

extern void *fn_80201B8C();

void fn_800CE8E8(void *object)
{
    Data *data = ((RuntimeState *)fn_80201B8C(object))->data;
    data->status = 0;
}
