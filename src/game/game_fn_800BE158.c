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
    unsigned char values[0x320];
    int cursor[2];
    unsigned char tail[0x10];
} Pool;

extern Slot lbl_80320DF0[];
extern Pool lbl_80320FD0[];
extern int fn_800BE1F4(void *, RuntimeState *);
extern void *memset(void *, int, unsigned long);

int fn_800BE158(void *object, RuntimeState *runtime)
{
    Pool *pool;

    if (fn_800BE1F4(object, runtime) == 0) {
        lbl_80320DF0[runtime->slot_index].state = -1;
        pool = &lbl_80320FD0[runtime->pool_index];
        pool->cursor[0] = 0;
        pool->cursor[1] = 0;
        memset(pool->values, 0, 0x320);
        return 1;
    }
    return 0;
}
