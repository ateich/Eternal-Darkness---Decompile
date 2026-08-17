typedef struct State {
    unsigned char pad[184];
    unsigned short count;
} State;

typedef struct Owner {
    unsigned char pad[60];
    State* state;
} Owner;

void fn_8011EA00(Owner* owner)
{
    unsigned short count;
    unsigned short i;

    if (owner == 0) {
        return;
    }
    if (owner->state == 0) {
        return;
    }

    count = owner->state->count;
    for (i = 0; i < count; i++) {
    }
}
