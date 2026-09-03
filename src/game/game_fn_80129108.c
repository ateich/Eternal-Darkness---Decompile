typedef unsigned char u8;
typedef signed int s32;

typedef struct Runtime {
    u8 pad0[0xF4];
    s32 flags;
} Runtime;

#define FN_80128E30_RETURN Runtime*
#define FN_80128E30_PARAMETERS void*
extern FN_80128E30_RETURN fn_80128E30(FN_80128E30_PARAMETERS);

s32 fn_80129108(void* owner, long clearMask, long setMask)
{
    Runtime* runtime = fn_80128E30(owner);
    s32 oldFlags = runtime->flags;
    runtime->flags &= ~clearMask;
    runtime->flags |= setMask;
    return oldFlags;
}
