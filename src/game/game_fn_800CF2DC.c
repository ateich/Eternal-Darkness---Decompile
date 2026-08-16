typedef unsigned char u8;
typedef signed short s16;

typedef struct Payload {
    int owner;
    unsigned int pad4;
    float scale;
    float padC;
    s16 x;
    s16 y;
    u8 kind;
} Payload;

typedef struct RuntimeState {
    u8 pad0[0x18];
    Payload *payload;
} RuntimeState;

extern void *fn_80201B8C();
extern void fn_80026DC8(s16, s16, float, float, s16, s16, u8, int);

void fn_800CF2DC(void *object)
{
    Payload *payload = ((RuntimeState *)fn_80201B8C(object))->payload;
    fn_80026DC8(payload->x, payload->y, payload->scale, payload->scale,
                payload->x + 0x7D, payload->y + 0xF,
                payload->kind, 0);
}
