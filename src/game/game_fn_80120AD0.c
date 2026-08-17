typedef unsigned short u16;
typedef unsigned u32;

typedef struct Position {
    u32 x;
    u32 y;
    u32 z;
} Position;

typedef struct Object {
    unsigned char pad[0x2B0];
    Position position;
    float first;
    float second;
    unsigned char pad2[0xE];
    u16 state;
    u16 value;
} Object;

void fn_80120AD0(Object* object, const Position* position, u16 value, u32 state,
                 float first, float second)
{
    u32 state_value;
    int priority;
    int old_priority;

    if (object == 0) {
        return;
    }

    state_value = state & 0xFFFF;
    priority = state & 0x1FC;
    old_priority = object->state & 0x1FC;
    if (priority >= old_priority || state_value == 1) {
        if (position != 0) {
            object->position = *position;
        }
        object->state = state;
        object->first = first;
        object->second = second;
        object->value = value;
        return;
    }

    if (state_value == 0) {
        object->state = 0;
        object->first = first;
        object->second = second;
        object->value = value;
    }
}
