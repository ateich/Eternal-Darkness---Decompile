typedef unsigned char u8;
typedef signed short s16;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Resource {
    u8 pad[0x2C];
    int slots[3];
} Resource;

typedef struct RuntimeState {
    u8 pad[0x2C];
    void *payload;
    u8 pad30[0x5C];
    Resource *resource;
} RuntimeState;

typedef struct Payload {
    u8 flags;
    u8 pad01[7];
    int first;
    int second;
    int fourth;
    s16 fifth;
    u8 pad16[6];
    void *third;
    void *eighth;
    Vec3 position;
} Payload;

extern void *fn_80201814();
extern RuntimeState *fn_80201B8C();
extern int fn_80201B44();
extern unsigned long long fn_8020123C();
extern void *fn_80037AF4(int);
extern int fn_80201B54();
extern void fn_802015A4(void *);
extern void fn_801E8328(int, void *);
extern void fn_8020104C(int, int, int, int, float);

#pragma use_lmw_stmw on
void *fn_800CD6C0(int argFirst, int argSecond, void *argThird, u8 argFlags,
                  int argFourth, s16 argFifth, Vec3 *argPosition, float time,
                  void *argEighth)
{
    void *object = 0;
    int slot = 0;
    RuntimeState *state = 0;
    int id;
    int first = argFirst;
    int second = argSecond;
    void *third = argThird;
    u8 flags = argFlags;
    int fourth = argFourth;
    s16 fifth = argFifth;
    Vec3 *position = argPosition;
    void *eighth = argEighth;
    void *resolved;
    Payload *payload;

    resolved = fn_80201814(first);
    if (resolved != 0) {
        state = fn_80201B8C(resolved);
        if (first == fn_80201B44(state)) {
            int linked = state->resource->slots[0];
            if (linked != 0) {
                fn_8020123C(0x39, linked, linked, 0);
            }
            slot = 0;
        } else {
            slot = 0;
            if (state->resource->slots[0] != 0) {
                slot = 1;
                if (state->resource->slots[1] != 0) {
                    slot = 2;
                    if (state->resource->slots[2] != 0) {
                        slot = 3;
                    }
                }
            }
        }
    }
    if (slot < 3) {
        object = fn_80037AF4(0x19);
        id = fn_80201B54(object);
        if (state != 0) {
            state->resource->slots[slot] = id;
        }
        payload = (Payload *)fn_80201B8C(object)->payload;
        payload->flags = flags;
        payload->first = first;
        payload->second = second;
        payload->fourth = fourth;
        payload->fifth = fifth;
        payload->third = third;
        payload->position = *position;
        payload->eighth = eighth;
        fn_802015A4(object);
        fn_801E8328(0x15, object);
        if ((payload->flags & 6) == 0) {
            fn_8020104C(0x39, id, id, 0, time);
        }
    }
    return object;
}
