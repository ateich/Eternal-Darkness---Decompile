typedef struct LuaState LuaState;
typedef struct HashTable HashTable;

typedef struct Value {
    int type;
    int pad4;
    union {
        double number;
        void* pointer;
    } data;
} Value;

extern Value* fn_801671D0(LuaState*, HashTable*, Value*);
extern Value* fn_80167264(HashTable*, double);
extern Value* fn_801672C8(HashTable*, void*);

Value* fn_8016731C(LuaState* state, HashTable* table, Value* value)
{
    switch (value->type) {
    case 2:
        return fn_80167264(table, value->data.number);
    case 3:
        return fn_801672C8(table, value->data.pointer);
    default:
        return fn_801671D0(state, table, value);
    }
}
