typedef struct TableState {
    int size;
    int nuse;
    void** hash;
} TableState;

typedef struct LuaState {
    char pad0[0x2C];
    TableState strt;
    TableState udt;
    char pad44[0x1C];
    int nblocks;
} LuaState;

extern void* fn_8016B5CC(LuaState*, void*, int, const char*, int);
extern const char lbl_8024FA38[];

void fn_80166AC4(LuaState* state)
{
    state->strt.hash = fn_8016B5CC(state, 0, sizeof(void*), lbl_8024FA38, 29);
    state->udt.hash = fn_8016B5CC(state, 0, sizeof(void*), lbl_8024FA38, 30);
    state->nblocks += 2 * sizeof(void*);
    state->strt.size = state->udt.size = 1;
    state->strt.nuse = state->udt.nuse = 0;
    state->strt.hash[0] = state->udt.hash[0] = 0;
}
