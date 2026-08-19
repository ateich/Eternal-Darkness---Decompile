typedef struct TObject {
    int tag;
    char value[12];
} TObject;

typedef struct TableState {
    int size;
    int nuse;
    void* hash;
} TableState;

typedef struct LuaState {
    TObject* top;
    TObject* stack;
    TObject* stack_last;
    int stacksize;
    TObject* Cbase;
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

extern void fn_80161ED8(LuaState*, int);
extern void fn_80166B5C(LuaState*);
extern void* fn_8016B5CC(LuaState*, void*, int, const char*, int);
extern const char lbl_8024FA28[];

void fn_80166994(LuaState* state)
{
    fn_80161ED8(state, 1);
    fn_80166B5C(state);
    if (state->stack) {
        state->nblocks -= (state->stack_last - state->stack + 1) * sizeof(TObject);
    }
    fn_8016B5CC(state, state->stack, 0, lbl_8024FA28, 110);
    state->nblocks -= (state->last_tag + 1) * 64;
    fn_8016B5CC(state, state->TMtable, 0, lbl_8024FA28, 112);
    state->nblocks -= state->refSize * 24;
    fn_8016B5CC(state, state->refArray, 0, lbl_8024FA28, 114);
    state->nblocks -= state->Mbuffsize;
    fn_8016B5CC(state, state->Mbuffer, 0, lbl_8024FA28, 116);
    fn_8016B5CC(state, state, 0, lbl_8024FA28, 118);
}
