typedef struct ObjectState {
    unsigned char pad00[0x8C];
    struct SelectionState *selection;
} ObjectState;

typedef struct SelectionState {
    unsigned char pad00[0xAC];
    int group;
    int slot;
} SelectionState;

typedef struct SelectionTable {
    void *entries[2][100];
    int selected[2];
    unsigned char pad328[0x10];
} SelectionTable;

typedef struct SlotState {
    int side;
    unsigned char pad04[0x14];
} SlotState;

extern void *fn_80201B8C();
extern SlotState lbl_80320DF0[];
extern SelectionTable lbl_80320FD0[];

void fn_800BCD2C(void)
{
    ObjectState *object = fn_80201B8C();
    SelectionState *state = object->selection;
    int side = lbl_80320DF0[state->slot].side;
    int other_side = side ^ 1;
    SelectionTable *table = &lbl_80320FD0[state->group];
    int *selected = table->selected;
    void *wanted = table->entries[other_side][selected[other_side]];

    if (wanted != 0) {
        int i = 1;
        void **entry = &table->entries[side][1];

        while (*entry != 0 && i < 100) {
            if (wanted == *entry) {
                selected[side] = i;
                return;
            }
            entry++;
            i++;
        }
    }
    selected[side] = 0;
}
