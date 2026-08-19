typedef struct LuaState LuaState;
typedef struct HashTable HashTable;

typedef struct Value {
    int type;
    int pad4;
    double data;
} Value;

extern Value* fn_801679F8(LuaState*, HashTable*, Value*);

Value* fn_80167B5C(LuaState* state, HashTable* table, int key)
{
    Value value;

    value.type = 2;
    value.data = (double)key;
    return fn_801679F8(state, table, &value);
}
