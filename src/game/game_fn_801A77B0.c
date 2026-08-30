typedef unsigned int u32;

typedef struct {
    u32 first;
    u32 second;
} Result;

extern Result* fn_801A78C0(void*);

u32 fn_801A77B0(void* data)
{
    return fn_801A78C0(data)->second;
}
