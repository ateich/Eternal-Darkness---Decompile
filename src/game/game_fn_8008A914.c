typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Inner {
    u8 pad[0xC];
    u8 active;
} Inner;

typedef struct State {
    u8 pad[0x48];
    Inner* inner;
} State;

extern State* fn_80201B8C(void*);
extern void* fn_801294DC(void*, int, int, int);

void fn_8008A914(void* object, u32 flags, void* resource)
{
    if ((flags & 0x3FF) == 0 && fn_80201B8C(object)->inner->active == 0)
        fn_801294DC(resource, 0x10, 0x20, 1);
}
