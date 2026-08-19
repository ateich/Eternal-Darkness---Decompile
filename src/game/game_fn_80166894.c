typedef struct TableState {
    int size;
    int nuse;
    void* hash;
} TableState;

typedef struct LuaState {
    void* top;
    void* stack;
    void* stack_last;
    int stacksize;
    void* Cbase;
    void* errorJmp;
    void* Mbuffer;
    int Mbuffsize;
    void* rootproto;
    void* rootcl;
    void* roottable;
    TableState strt;
    TableState udt;
    void* gt;
    void* TMtable;
    int last_tag;
    void* refArray;
    int refSize;
    int refFree;
    int GCthreshold;
    int nblocks;
    void* callhook;
    void* linehook;
    int allowhooks;
} LuaState;

extern void* fn_8016B5CC(void*, void*, int, const char*, int);
extern int fn_80161044(LuaState*, void (*)(LuaState*, int*), int*);
extern void fn_801667E4(LuaState*, int*);
extern void fn_80166994(LuaState*);
extern const char lbl_8024FA28[];

LuaState* fn_80166894(int stacksize)
{
    LuaState* state = fn_8016B5CC(0, 0, sizeof(LuaState), lbl_8024FA28, 68);

    if (state == 0) {
        return 0;
    }
    state->stack = 0;
    state->strt.size = state->udt.size = 0;
    state->strt.nuse = state->udt.nuse = 0;
    state->strt.hash = 0;
    state->udt.hash = 0;
    state->Mbuffer = 0;
    state->Mbuffsize = 0;
    state->rootproto = 0;
    state->rootcl = 0;
    state->roottable = 0;
    state->TMtable = 0;
    state->last_tag = -1;
    state->refArray = 0;
    state->refSize = 0;
    state->refFree = -1;
    state->nblocks = sizeof(LuaState);
    state->GCthreshold = 0x7FFFFFFD;
    state->callhook = 0;
    state->linehook = 0;
    state->allowhooks = 1;
    state->errorJmp = 0;
    if (fn_80161044(state, fn_801667E4, &stacksize) != 0) {
        fn_80166994(state);
        return 0;
    }
    state->GCthreshold = 2 * state->nblocks;
    return state;
}
