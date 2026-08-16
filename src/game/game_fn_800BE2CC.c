typedef struct RuntimeState {
    unsigned char pad[0xAC];
    int pool_index;
    int slot_index;
} RuntimeState;

typedef struct Slot {
    int state;
    unsigned char pad[20];
} Slot;

typedef struct Item {
    void *value;
} Item;

typedef struct Pool {
    Item *items0[100];
    Item *items1[100];
    int cursor[2];
    unsigned char tail[0x10];
} Pool;

extern Slot lbl_80320DF0[];
extern Pool lbl_80320FD0[];
extern int fn_80201B54();
extern void fn_800BCCC4(void *, void *);

int fn_800BE2CC(void *object, RuntimeState *runtime, void *output)
{
    int state;
    Item *item;

    fn_80201B54(object);
    if (runtime->slot_index < 0 || runtime->pool_index < 0) {
        return 0;
    }
    state = lbl_80320DF0[runtime->slot_index].state;
    if (state != 0 && state != 1) {
        return 0;
    }
    item = ((Item **)((unsigned char *)&lbl_80320FD0[runtime->pool_index] + state * 0x190))
        [lbl_80320FD0[runtime->pool_index].cursor[state]];
    if (item == 0 || item->value == 0) {
        return 0;
    }
    fn_800BCCC4(item->value, output);
    return 1;
}
