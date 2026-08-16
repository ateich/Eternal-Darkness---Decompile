typedef unsigned char u8;
typedef unsigned short u16;

typedef struct RuntimeState {
    u8 pad[0x24];
    void *payload;
    u8 pad28[0x64];
    void *resource;
} RuntimeState;

typedef struct OwnerResource {
    u8 pad[0x24];
    int linked;
} OwnerResource;

typedef struct Payload {
    u16 kind;
    u8 pad2[0xB2];
    int owner;
    int first;
    int second;
    int third;
    int fourth;
} Payload;

extern void *fn_80201814(int);
extern RuntimeState *fn_80201B8C(void *);
extern void *fn_80037AF4(int);
extern int fn_80201B54(void *);
extern void fn_801DACA4(int, int);
extern void fn_801DABFC(Payload *);
extern void fn_801DA140(int, int, void *);
extern void fn_802015A4(void *);
extern void fn_801E8328(int, void *);

#pragma use_lmw_stmw on
void *fn_800CD458(int owner, int first, u16 kind, int second, int third,
                  int fourth, void *callback)
{
    void *object = 0;
    void *resolved = fn_80201814(owner);

    if (resolved != 0) {
        RuntimeState *state = fn_80201B8C(resolved);
        int linked = ((OwnerResource *)state->resource)->linked;
        int previous = linked;
        Payload *payload;

        if (linked != 0) {
            object = fn_80201814(linked);
        } else {
            object = fn_80037AF4(0x18);
            linked = fn_80201B54(object);
            ((OwnerResource *)state->resource)->linked = linked;
            fn_801DACA4(owner, 1);
        }

        payload = (Payload *)fn_80201B8C(object)->payload;
        if (previous != 0 && callback != 0) {
            fn_801DABFC(payload);
            fn_801DA140(owner, linked, callback);
        }
        payload->owner = owner;
        payload->first = first;
        payload->second = second;
        payload->third = third;
        payload->fourth = fourth;
        payload->kind = kind;
        if (previous == 0) {
            fn_802015A4(object);
            fn_801E8328(0x15, object);
        }
    }
    return object;
}
