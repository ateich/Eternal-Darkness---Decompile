typedef unsigned int u32;

typedef struct Slot {
    int id;
    unsigned char handle[0x3C];
    void* buffer;
    void* resource;
    u32 size;
    signed char state;
    signed char flag;
    unsigned char pad[2];
} Slot;

typedef struct State {
    int current;
    int arena_size;
    int request;
    int wanted;
    unsigned char pad10[0x2A8];
    Slot slots[2];
} State;

extern State lbl_805AE020;
extern int fn_801397F8(u32*, int, int, int);
extern void fn_801392A8(int, int);
extern void fn_80139940(int);
extern void fn_80139E04(void*, void*, void*, int, int);

int fn_80139464(void* object, int id)
{
    State* state = &lbl_805AE020;
    int other = state->current ^ 1;
    int result = 0;
    int free_slot = -1;

    state->request = (int)object;
    state->wanted = id;
    if (!fn_801397F8(0, 1, 1, 0)) {
        return 0;
    }

    if (state->slots[state->current].id != id && state->slots[other].id != id) {
        if (state->slots[state->current].flag == 0) {
            free_slot = state->current;
        } else if (state->slots[other].flag == 0) {
            free_slot = other;
        }
        if (free_slot != -1 && state->slots[free_slot].state != 1) {
            state->slots[free_slot].id = id;
            state->slots[free_slot].state = 0;
            state->slots[free_slot].resource = 0;
        }
    }

    if (state->slots[state->current].state == 0 &&
        state->slots[state->current].id != -1) {
        fn_801392A8(state->current, 0);
    }
    if (state->slots[other].state == 0 && state->slots[other].id != -1) {
        fn_801392A8(other, 1);
    }

    if (state->slots[other].id == id && state->slots[other].state == 2) {
        state->slots[other].flag = 1;
        fn_80139E04(object, state->slots[other].resource, (char*)state + 0x10,
                     (int)state->slots[other].size, 0xAA);
        if (state->slots[other].resource != 0) {
            result = 1;
        }
    } else if (state->slots[state->current].id == id &&
               state->slots[state->current].state == 2) {
        state->slots[state->current].flag = 1;
        fn_80139E04(object, state->slots[state->current].resource,
                     (char*)state + 0x10, (int)state->slots[state->current].size,
                     0xAA);
        if (state->slots[state->current].resource != 0) {
            result = 1;
        }
    }
    fn_80139940(0);
    return result;
}
