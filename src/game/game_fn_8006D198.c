typedef signed int s32;

typedef struct Owner {
    void *entries[4];
} Owner;

extern void fn_8006C9D4(void *entry, s32 value);

s32 fn_8006D198(Owner *owner, void *entry, s32 index)
{
    if (owner->entries[index + 1] == 0) {
        owner->entries[index + 1] = entry;
        fn_8006C9D4(entry, 6);
    }
    return 1;
}
