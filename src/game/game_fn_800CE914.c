typedef unsigned char u8;

typedef struct RuntimeState {
    u8 pad[0x1C];
    void *payload;
    u8 pad20[0x6C];
    void *resource;
} RuntimeState;

typedef struct Payload {
    u8 pad[0xE8];
    int owner;
} Payload;

typedef struct Resource {
    u8 pad[0x40];
    int linked;
} Resource;

extern void *fn_80037AF4(int);
extern RuntimeState *fn_80201B8C();
extern void fn_800CD1FC(Payload *, void *, void *, int);
extern int fn_80201B54();
extern void fn_802015A4(void *);

#pragma use_lmw_stmw on
void *fn_800CE914(void *owner, void *first, void *second, int third)
{
    void *object = fn_80037AF4(0x16);
    Payload *payload = (Payload *)fn_80201B8C(object)->payload;

    fn_800CD1FC(payload, first, second, third);
    payload->owner = fn_80201B54(owner);
    fn_802015A4(object);
    ((Resource *)fn_80201B8C(owner)->resource)->linked = fn_80201B54(object);
    return object;
}
