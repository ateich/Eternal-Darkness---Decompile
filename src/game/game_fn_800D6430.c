typedef struct Actor {
    unsigned char pad_000[0x86];
    unsigned short kind;
    unsigned char pad_088[0x10f];
    signed char field_197;
    int field_198;
} Actor;

void fn_800D6430(Actor *actor)
{
    switch (actor->kind) {
    case 0:
        actor->field_197 = 0;
        actor->field_198 = 1;
        break;
    case 1:
        actor->field_197 = 0;
        actor->field_198 = 0;
        break;
    case 2:
        actor->field_197 = 0;
        actor->field_198 = 14;
        break;
    case 3:
        actor->field_197 = 0;
        actor->field_198 = -1;
        break;
    }
}
