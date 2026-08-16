typedef unsigned char u8;
typedef signed short s16;

typedef struct Vec3f {
    float x;
    float y;
    float z;
} Vec3f;

typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

typedef struct Payload {
    Vec3f position;
    int value;
    int owner;
    s16 pad14[3];
    s16 field1A;
    s16 field1C;
    s16 field1E;
    s16 field20;
    u8 field22;
} Payload;

typedef struct RuntimeState {
    u8 pad0[0x74];
    Payload *payload;
} RuntimeState;

extern void *fn_80037AF4(int);
extern void *fn_80201B8C();
extern void fn_802015A4(void *);
extern int fn_801E8328(int, void *);

#pragma use_lmw_stmw on
void *fn_800CF46C(Vec3f *position, Vec3s *rotation, s16 field1C,
                  int owner, s16 field1E, u8 field22, s16 field20, int value)
{
    void *object = fn_80037AF4(0x4D);
    Payload *payload = ((RuntimeState *)fn_80201B8C(object))->payload;

    payload->position.x = position->x;
    payload->position.y = position->y;
    payload->position.z = position->z;
    payload->pad14[0] = rotation->x;
    payload->pad14[1] = rotation->y;
    payload->pad14[2] = rotation->z;
    payload->value = value;
    payload->field1A = 0;
    payload->field1C = field1C;
    payload->field20 = field20;
    payload->field1E = field1E;
    payload->owner = owner;
    payload->field22 = field22;
    fn_802015A4(object);
    fn_801E8328(0x15, object);
    return object;
}
