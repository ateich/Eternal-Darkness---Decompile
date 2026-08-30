typedef unsigned int u32;

typedef struct {
    u32 first;
} Result;

extern Result* fn_801A78C0(void*);

u32 fn_801A77D4(void* data)
{
    return fn_801A78C0(data)->first;
}
