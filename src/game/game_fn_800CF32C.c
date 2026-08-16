typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Payload {
    int owner;
    unsigned int pad4;
    float first;
    float second;
    u16 first_id;
    u16 second_id;
    u8 flag;
} Payload;

typedef struct RuntimeState {
    u8 pad0[0x18];
    Payload *payload;
    u8 pad1C[0x70];
    void *links;
} RuntimeState;

extern void *fn_80037AF4(int);
extern RuntimeState *fn_80201B8C(void *);
extern int fn_80201B54(void *);
extern void fn_802015A4(void *);

#pragma use_lmw_stmw on
void *fn_800CF32C(void *owner, u16 first_id, u16 second_id, u8 flag,
                  float first, float second)
{
    void *object = fn_80037AF4(0x14);
    Payload *payload = fn_80201B8C(object)->payload;
    int object_id;

    payload->owner = fn_80201B54(owner);
    payload->first = first;
    payload->second = second;
    payload->first_id = first_id;
    payload->second_id = second_id;
    payload->flag = flag;
    fn_802015A4(object);
    object_id = fn_80201B54(object);
    *(int *)((u8 *)fn_80201B8C(owner)->links + 0x10) = object_id;
    return object;
}
