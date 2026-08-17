typedef unsigned char u8;
typedef signed int s32;

typedef struct Runtime {
    u8 pad0[0xF4];
    s32 flags;
} Runtime;

extern Runtime* fn_80128E30(void*);

s32 fn_80129108(void* owner, s32 clearMask, s32 setMask)
{
    Runtime* runtime = fn_80128E30(owner);
    s32 oldFlags = runtime->flags;
    runtime->flags &= ~clearMask;
    runtime->flags |= setMask;
    return oldFlags;
}
