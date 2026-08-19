typedef struct LuaState LuaState;

typedef struct Value {
    int type;
    int pad4;
    double data;
} Value;

typedef struct HashNode {
    Value key;
    Value value;
    struct HashNode* next;
    int pad24;
} HashNode;

typedef struct HashTable {
    HashNode* nodes;
    int pad4;
    int size;
    HashNode* firstfree;
} HashTable;

#pragma use_lmw_stmw on

extern HashNode* fn_80167128(HashTable*, Value*);
extern int fn_801639E8(Value*, HashNode*);
extern void fn_80160FAC(LuaState*, const char*);
extern void fn_801678F4(LuaState*, HashTable*);
extern const char lbl_8024FA48[];

Value* fn_801679F8(LuaState* state, HashTable* table, Value* key)
{
    HashNode* mainnode = fn_80167128(table, key);
    HashNode* node = mainnode;

    if (mainnode == 0) {
        fn_80160FAC(state, lbl_8024FA48);
    }

    do {
        if (fn_801639E8(key, node)) {
            return &node->value;
        }
        node = node->next;
    } while (node != 0);

    if (mainnode->key.type != 1) {
        node = table->firstfree;
        if (mainnode > node) {
            HashNode* other = fn_80167128(table, &mainnode->key);
            if (other != mainnode) {
                while (other->next != mainnode) {
                    other = other->next;
                }
                other->next = node;
                *node = *mainnode;
                mainnode->next = 0;
                goto set_key;
            }
        }
        node->next = mainnode->next;
        mainnode->next = node;
        mainnode = node;
    }

set_key:
    mainnode->key = *key;

    for (;;) {
        if (table->firstfree->key.type == 1) {
            return &mainnode->value;
        }
        if (table->firstfree != table->nodes) {
            table->firstfree--;
        } else {
            fn_801678F4(state, table);
            return fn_801679F8(state, table, key);
        }
    }
}
