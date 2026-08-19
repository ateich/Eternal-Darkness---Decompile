typedef struct LuaState {
    char pad0[0x60];
    int nblocks;
} LuaState;

typedef struct Value {
    int type;
    int pad4;
    double data;
} Value;

typedef struct HashNode {
    Value key;
    Value value;
    struct HashNode* next;
    char pad24[4];
} HashNode;

typedef struct HashTable {
    HashNode* nodes;
    int pad4;
    int size;
    HashNode* firstfree;
} HashTable;

#pragma use_lmw_stmw on

extern int fn_801678BC(HashTable*);
extern void fn_80167558(LuaState*, HashTable*, int);
extern Value* fn_801679F8(LuaState*, HashTable*, Value*);
extern void* fn_8016B5CC(LuaState*, void*, unsigned int, const char*, int);
extern const char lbl_8024FA84[];

void fn_801678F4(LuaState* state, HashTable* table)
{
    HashNode* node;
    int oldsize = table->size;
    HashNode* oldnodes = table->nodes;
    int i;
    int count = fn_801678BC(table);
    int quarter = oldsize / 4;

    if (count >= oldsize - quarter) {
        fn_80167558(state, table, oldsize * 4);
    } else if (count <= quarter && oldsize > 4) {
        fn_80167558(state, table, oldsize / 2);
    } else {
        fn_80167558(state, table, oldsize);
    }

    node = oldnodes;
    for (i = 0; i < oldsize; node++, i++) {
        if (node->value.type != 1) {
            *fn_801679F8(state, table, &node->key) = node->value;
        }
    }

    fn_8016B5CC(state, oldnodes, 0, lbl_8024FA84, 229);
}
