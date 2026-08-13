typedef signed int s32;
typedef unsigned short u16;

typedef struct Entry {
    unsigned char pad_0[10];
    u16 type;
} Entry;

typedef struct Flags {
    unsigned char pad_0[20];
    s32 first;
    s32 second;
} Flags;

typedef struct Owner {
    void *pad_0;
    Entry *entry;
    unsigned char pad_8[0xBC];
    Flags *flags;
} Owner;

extern s32 fn_80070AAC(Owner *owner);

s32 fn_8006D344(Owner *owner, s32 first, s32 second)
{
    s32 result = 0;

    if ((fn_80070AAC(owner) & 0x10000) == 0 && owner != 0 &&
        owner->entry != 0) {
        u16 type = owner->entry->type;
        Flags *flags = owner->flags;
        if (type == 4) {
            if ((flags->first & first) != 0) {
                result = 1;
            }
            if ((flags->second & second) != 0) {
                result = 1;
            }
        }
    }
    return result;
}
