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

extern RuntimeState *fn_80201B8C(void *);

void fn_800CE8E8(void *object)
{
    Data *data = fn_80201B8C(object)->data;
    data->status = 0;
}
