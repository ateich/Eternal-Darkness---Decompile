typedef struct RuntimeState {
    unsigned char pad[0xAC];
    int pool_index;
    int slot_index;
} RuntimeState;

typedef struct Slot {
    int state;
    unsigned char pad[20];
} Slot;

typedef struct Pool {
    unsigned char pad[0x320];
    int cursor[2];
    unsigned char tail[0x10];
} Pool;

extern Slot lbl_80320DF0[];
extern Pool lbl_80320FD0[];
extern int fn_80201B54(void *);

void fn_800BE390(void *object, RuntimeState *runtime)
{
    int state;

    fn_80201B54(object);
    if (runtime->slot_index >= 0 && runtime->pool_index >= 0) {
        state = lbl_80320DF0[runtime->slot_index].state;
        lbl_80320FD0[runtime->pool_index].cursor[state]++;
    }
}
