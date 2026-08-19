typedef struct Value Value;
typedef struct HashTable HashTable;

typedef struct LuaState {
    char pad0[0x44];
    HashTable* table;
} LuaState;

extern Value* fn_801670A8(LuaState*, const char*);
extern Value* fn_801672C8(HashTable*, Value*);

Value* fn_80167BF0(LuaState* state, const char* name)
{
    return fn_801672C8(state->table, fn_801670A8(state, name));
}
