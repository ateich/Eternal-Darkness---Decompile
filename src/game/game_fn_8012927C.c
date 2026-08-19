typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Definition {
    u8 pad0[8];
    u16 limit;
} Definition;

typedef struct Record {
    u8 pad0[0x24];
    u16 value24;
} Record;

typedef struct Node {
    u8 pad0[8];
    Record* record;
} Node;

typedef struct Runtime {
    u8 pad0[0xB8];
    Node* node;
} Runtime;

typedef struct Owner {
    u8 pad0[0x3C];
    Definition* definition;
} Owner;

#define FN_80128E30_RETURN Runtime*
#define FN_80128E30_PARAMETERS Owner*
extern FN_80128E30_RETURN fn_80128E30(FN_80128E30_PARAMETERS);

u16 fn_8012927C(Owner* owner)
{
    Node* node = fn_80128E30(owner)->node;
    u16 result;

    if (node == 0) {
        result = 0xFFFF;
    } else {
        result = node->record->value24;
        if (result > owner->definition->limit) {
            result = 0xFFFF;
        }
    }
    return result;
}
