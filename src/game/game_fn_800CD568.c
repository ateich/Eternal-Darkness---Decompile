typedef unsigned char u8;

typedef struct RuntimeState {
    u8 pad[0x28];
    void *payload;
    u8 pad2C[0x60];
    void *resource;
} RuntimeState;

typedef struct OwnerResource {
    u8 pad[0x28];
    int linked;
} OwnerResource;

typedef struct Payload {
    int resource;
    int first;
    int owner;
    int second;
    void *third;
    void *fourth;
} Payload;

extern const float lbl_8064F2B0;
extern const float lbl_8064F30C;
extern void *fn_80201814();
extern RuntimeState *fn_80201B8C();
extern void fn_802006D4(int, int, int, int, int);
extern void *fn_80037AF4(int);
extern int fn_80201B54();
extern void fn_801E32F8(Payload *);
extern void fn_802015A4(void *);
extern int fn_801E8328(int, void *);
extern void fn_8020104C(int, int, int, int, float);

#pragma use_lmw_stmw on
void *fn_800CD568(int first, int owner, int second, void *third, float time,
                  void *fourth, void *resource)
{
    void *resolved;
    RuntimeState *state;
    void *object = 0;
    int linked;
    int previous;
    Payload *payload;

    resolved = fn_80201814(owner);
    if (resolved != 0) {
        state = fn_80201B8C(resolved);
        linked = ((OwnerResource *)state->resource)->linked;
        previous = linked;
        if (linked != 0) {
            object = fn_80201814(linked);
            fn_802006D4(linked, linked, -1, 0x39, 0);
        } else {
            object = fn_80037AF4(0x57);
            if (object != 0) {
                linked = fn_80201B54(object);
                ((OwnerResource *)state->resource)->linked = linked;
            }
        }
        if (object != 0) {
            payload = (Payload *)fn_80201B8C(object)->payload;
            if (previous != 0) {
                fn_801E32F8(payload);
            }
            payload->first = first;
            payload->owner = owner;
            payload->second = second;
            payload->third = third;
            payload->fourth = fourth;
            payload->first = first;
            payload->resource = (int)resource;
            if (previous == 0) {
                fn_802015A4(object);
                fn_801E8328(0x15, object);
            }
            if (time <= lbl_8064F2B0) {
                time = lbl_8064F30C;
            }
            fn_8020104C(0x39, linked, linked, 0, time);
        }
    }
    return object;
}
