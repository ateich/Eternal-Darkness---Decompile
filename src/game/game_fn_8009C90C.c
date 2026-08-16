typedef unsigned char u8;

typedef struct State8009C90C {
    u8 pad00[0xC0];
    int actors[8];
} State8009C90C;

extern void *fn_80201814();
extern int fn_8009C870(State8009C90C*, int);

int fn_8009C90C(register State8009C90C* state)
{
    register State8009C90C* cursor;
    register unsigned int i;
    register int result;
    register int actor_id;

    result = 0;
    i = 0;
    cursor = state;
    do {
        actor_id = cursor->actors[0];
        if (actor_id != 0 && fn_80201814(actor_id) == 0) {
            result = fn_8009C870(state, actor_id);
        }
        i++;
        cursor = (State8009C90C*)((u8*)cursor + 4);
    } while (i < 8);
    return result;
}
