typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Payload {
    unsigned int pad0;
    float first;
    float second;
    u8 padC[0xC];
    int owner;
    int slot;
    u16 first_id;
    u16 second_id;
    u16 extra;
    u8 pad26[4];
    u8 flag0;
    u8 flag1;
} Payload;

typedef struct RuntimeState {
    void *base;
    u8 pad4[0x10];
    Payload *payload;
} RuntimeState;

extern void *fn_80037AF4(int);
extern RuntimeState *fn_80201B8C();
extern int fn_80201B54();
extern void fn_802015A4(void *);

#pragma use_lmw_stmw on
void *fn_800CF220(void *owner, u16 first_id, u16 second_id, u8 flag,
                  int slot, u16 extra, float first, float second)
{
    void *object = fn_80037AF4(0x46);
    Payload *payload = fn_80201B8C(object)->payload;
    int object_id;

    payload->owner = fn_80201B54(owner);
    payload->slot = slot;
    payload->first = first;
    payload->second = second;
    payload->first_id = first_id;
    payload->second_id = second_id;
    payload->extra = extra;
    payload->flag0 = flag;
    payload->flag1 = flag;
    fn_802015A4(object);
    object_id = fn_80201B54(object);
    *(int *)((u8 *)fn_80201B8C(owner)->base + 0x70) = object_id;
    return object;
}
