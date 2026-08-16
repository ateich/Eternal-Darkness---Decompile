typedef struct RuntimeState {
    unsigned char pad[0xAC];
    int pool_index;
    int slot_index;
} RuntimeState;

typedef struct Slot {
    unsigned char pad[20];
    unsigned char flags;
    unsigned char tail[3];
} Slot;

extern Slot lbl_80320DF0[];
extern int fn_80201B54(void *);

int fn_800BE1F4(void *object, RuntimeState *runtime)
{
    int result = 0;
    fn_80201B54(object);
    if (runtime->slot_index >= 0 && runtime->pool_index >= 0) {
        result = lbl_80320DF0[runtime->slot_index].flags & 2;
    }
    return result;
}
