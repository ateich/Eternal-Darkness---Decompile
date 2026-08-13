typedef signed int s32;
typedef unsigned short u16;

typedef struct Resource {
    s32 value;
    char pad4[6];
    u16 kind;
} Resource;

typedef struct Owner {
    char pad0[4];
    Resource *resource;
} Owner;

extern s32 fn_80070AAC(Owner *owner);

s32 fn_8006BCE4(Owner *owner)
{
    s32 result = -1;
    Resource *resource = owner->resource;

    if (resource != 0 && resource->kind == 4 &&
        (fn_80070AAC(owner) & 0x10000) == 0) {
        result = resource->value;
    }
    return result;
}
