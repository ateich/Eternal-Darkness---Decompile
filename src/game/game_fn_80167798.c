typedef struct LuaState LuaState;
typedef struct HashTable HashTable;

struct LuaState {
    char pad0[0x28];
    HashTable* tables;
    char pad2C[0x34];
    int nblocks;
};

struct HashTable {
    void* nodes;
    int marked;
    int size;
    void* firstfree;
    HashTable* next;
    HashTable* self;
};

extern void* fn_8016B5CC(LuaState*, void*, unsigned int, const char*, int);
extern int fn_801639CC(int);
extern void fn_80167558(LuaState*, HashTable*, int);
extern const char lbl_8024FA84[];

HashTable* fn_80167798(LuaState* state, int requested)
{
    HashTable* table = fn_8016B5CC(state, 0, 24, lbl_8024FA84, 178);

    table->marked = 4;
    table->next = state->tables;
    state->tables = table;
    table->self = table;
    table->size = 0;
    state->nblocks += 24;
    table->nodes = 0;
    fn_80167558(state, table, fn_801639CC(requested));
    return table;
}
