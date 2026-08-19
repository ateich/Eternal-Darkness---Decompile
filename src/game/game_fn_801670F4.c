typedef struct LuaState LuaState;

typedef struct StringNode {
    int hash;
    int marked;
    int length;
    void* next;
    int type;
} StringNode;

extern StringNode* fn_801670A8(LuaState*, const char*);

StringNode* fn_801670F4(LuaState* state, const char* string)
{
    StringNode* node = fn_801670A8(state, string);

    if (node->type == 0) {
        node->type = 2;
    }
    return node;
}
