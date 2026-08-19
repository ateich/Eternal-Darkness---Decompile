typedef struct LuaState LuaState;
typedef struct HashTable HashTable;
typedef struct Value Value;

typedef struct HashNode {
    char pad0[0x10];
    Value* result;
    char pad14[0xC];
    struct HashNode* next;
} HashNode;

extern HashNode* fn_80167128(HashTable*, Value*);
extern int fn_801639E8(Value*, HashNode*);
extern void fn_80160FAC(LuaState*, const char*);
extern const char lbl_8024FA48[];
extern Value lbl_8023A868;

Value* fn_801671D0(LuaState* state, HashTable* table, Value* value)
{
    HashNode* node = fn_80167128(table, value);

    if (node == 0) {
        fn_80160FAC(state, lbl_8024FA48);
    } else {
        do {
            if (fn_801639E8(value, node)) {
                return (Value*)((char*)node + 0x10);
            }
            node = node->next;
        } while (node != 0);
    }
    return &lbl_8023A868;
}
