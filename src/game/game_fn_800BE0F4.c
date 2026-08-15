typedef struct RuntimeState {
    unsigned char pad[0xAC];
    int pool_index;
    int slot_index;
} RuntimeState;

typedef struct Slot {
    int state;
    unsigned char pad[20];
} Slot;

extern Slot lbl_80320DF0[];
extern void fn_80201B54(void *);

int fn_800BE0F4(void *object, RuntimeState *runtime)
{
    fn_80201B54(object);
    if (runtime->slot_index >= 0 && runtime->pool_index >= 0) {
        return lbl_80320DF0[runtime->slot_index].state >= 0;
    }
    return 0;
}
