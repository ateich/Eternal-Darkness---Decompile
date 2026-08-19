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

extern Value* fn_801679F8(LuaState*, HashTable*, Value*);

void fn_80167BA8(LuaState* state, HashTable* table, void* key, double number)
{
    Value value;
    Value* result;

    value.type = 3;
    value.data.pointer = key;
    result = fn_801679F8(state, table, &value);
    result->type = 2;
    result->data.number = number;
}
