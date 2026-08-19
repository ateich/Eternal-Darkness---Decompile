typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Payload {
    unsigned int pad0;
    float first;
    float second;
    float selected;
    float value;
    u8 pad14[4];
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
    u8 pad0[0x14];
    Payload *payload;
    u8 pad18[0x74];
    int *slots;
} RuntimeState;

extern float lbl_8064F29C;
extern float lbl_8064F334;
extern float lbl_8064F338;
extern float lbl_8064F33C;
extern void *fn_80037AF4(int);
extern void *fn_80201B8C();
extern int fn_80201B54();
extern void fn_802015A4(void *);
extern int fn_80038464(void *, int, short *);

#pragma use_lmw_stmw on
void *fn_800CF0C8(void *owner, u16 first_id, u16 second_id, u8 flag,
                  int slot, u16 extra, float first, float second)
{
    void *object = fn_80037AF4(0xB);
    Payload *payload = ((RuntimeState *)fn_80201B8C(object))->payload;
    short value;
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
    fn_80038464(owner, slot, &value);

    switch (value) {
    case 75:
        payload->value = lbl_8064F334;
        break;
    case 100:
        payload->value = lbl_8064F29C;
        break;
    case 125:
        payload->value = lbl_8064F338;
        break;
    case 150:
        payload->value = lbl_8064F33C;
        break;
    default:
        payload->value = lbl_8064F29C;
        break;
    }
    payload->selected = payload->value;
    fn_802015A4(object);
    object_id = fn_80201B54(object);
    ((RuntimeState *)fn_80201B8C(owner))->slots[slot + 1] = object_id;
    return object;
}
