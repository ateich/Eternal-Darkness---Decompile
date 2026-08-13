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

s32 fn_8006BCB4(Owner *owner)
{
    s32 result = -1;

    if (owner != 0 && owner->resource != 0 && owner->resource->kind == 5) {
        result = owner->resource->value;
    }
    return result;
}
