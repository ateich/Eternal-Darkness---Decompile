typedef struct LuaState {
    char pad0[0x60];
    int nblocks;
} LuaState;

typedef struct HashTable {
    void* nodes;
    int pad4;
    int size;
} HashTable;

extern void* fn_8016B5CC(LuaState*, void*, unsigned int, const char*, int);
extern const char lbl_8024FA84[];

void fn_8016783C(LuaState* state, HashTable* table)
{
    state->nblocks -= table->size * 40 + 24;
    fn_8016B5CC(state, table->nodes, 0, lbl_8024FA84, 193);
    fn_8016B5CC(state, table, 0, lbl_8024FA84, 194);
}
