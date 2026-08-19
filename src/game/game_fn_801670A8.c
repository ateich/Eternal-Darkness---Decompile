typedef struct LuaState LuaState;
typedef struct StringNode StringNode;

extern unsigned int strlen(const char*);
extern StringNode* fn_80166E3C(LuaState*, const char*, unsigned int);

StringNode* fn_801670A8(LuaState* state, const char* string)
{
    return fn_80166E3C(state, string, strlen(string));
}
