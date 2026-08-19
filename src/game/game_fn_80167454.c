typedef struct Value {
    int type;
    int pad4;
    union {
        double number;
        void* pointer;
    } data;
} Value;

typedef struct HashNode {
    char pad0[0x28];
} HashNode;

typedef struct HashTable {
    HashNode* nodes;
    int pad4;
    int size;
} HashTable;

#pragma use_lmw_stmw on
#pragma opt_propagation off

extern HashNode* fn_80167128(HashTable*, Value*);
extern Value* fn_80167264(HashTable*, double);
extern Value lbl_8023A868;

void fn_80167454(HashTable* table, Value* value)
{
    HashNode* node;
    int index;

    if (value->type == 2) {
        return;
    }
    if (value->type == 3) {
        if (*(unsigned int*)((char*)value->data.pointer + 8) > 30) {
            goto find_key;
        }
        return;
    }

find_key:
    node = fn_80167128(table, value);
    index = ((char*)node - (char*)table->nodes) / 40;

    do {
        if (index >= 0x7FFFFFFD - table->size) {
            return;
        }
        index += table->size;
    } while (fn_80167264(table, (double)index) != &lbl_8023A868);

    value->type = 2;
    value->data.number = (double)index;
}
