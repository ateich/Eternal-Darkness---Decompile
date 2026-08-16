typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct OwnerResource {
    u8 pad[0x4C];
    int slots[2];
} OwnerResource;

typedef struct RuntimeState {
    u8 pad[0x4C];
    void *payload;
    u8 pad50[0x3C];
    OwnerResource * volatile owner_resource;
} RuntimeState;

typedef struct Payload {
    u8 pad0[8];
    int value;
    u8 padC[8];
    int first;
    int second;
    int third;
    int fourth;
    int owner_model;
    void *related_model;
    Vec3 position;
    u8 pad38[0xC4];
    u8 byte_fc;
    u8 byte_fd;
    u16 half_fe;
} Payload;

extern void *fn_80037AF4(int);
extern RuntimeState *fn_80201B8C();
extern void *fn_80201B54();
extern void fn_802015A4(void *);
extern int fn_801E8328(int, void *);

#pragma use_lmw_stmw on
void *fn_800CCF60(void *owner, int first, int second, void *related,
                  int third, int fourth, Vec3 *position, int value,
                  int byte_fc, int byte_fd, u16 half_fe)
{
    void *object = fn_80037AF4(0x2B);
    Payload *payload = (Payload *)fn_80201B8C(object)->payload;

    payload->byte_fc = byte_fc;
    payload->byte_fd = byte_fd;
    payload->half_fe = half_fe;
    payload->owner_model = (int)fn_80201B54(owner);
    payload->first = first;
    payload->second = second;
    if (related != 0) {
        payload->related_model = fn_80201B54(related);
        payload->third = third;
        payload->fourth = fourth;
    } else {
        payload->related_model = 0;
        payload->position = *position;
    }
    payload->value = value;
    fn_802015A4(object);

    payload = (Payload *)fn_80201B54(object);
    {
        RuntimeState *state = fn_80201B8C(owner);
        OwnerResource *resource = state->owner_resource;
        int slot;
        slot = 0;
        if (resource->slots[0] != 0) {
            slot = 1;
            if (resource->slots[1] != 0) {
                slot = 2;
            }
        }
        if (slot < 2) {
            state->owner_resource->slots[slot] = (int)payload;
        }
    }
    fn_801E8328(0x15, object);
    return object;
}
