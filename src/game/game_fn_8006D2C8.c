typedef signed int s32;
typedef unsigned short u16;

typedef struct Entry {
    s32 kind;
    unsigned char pad_4[6];
    u16 type;
} Entry;

typedef struct Owner {
    void *pad_0;
    Entry *entry;
} Owner;

extern s32 fn_80070AAC(Owner *owner);

s32 fn_8006D2C8(Owner *owner, s32 kind)
{
    s32 result = 0;

    if (owner != 0 && (fn_80070AAC(owner) & 0x10000) == 0 &&
        owner->entry != 0 && owner->entry->kind == kind &&
        owner->entry->type == 4) {
        result = 1;
    }
    return result;
}
