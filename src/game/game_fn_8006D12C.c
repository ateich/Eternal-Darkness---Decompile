typedef signed int s32;

typedef struct Owner {
    void *pad_0;
    void *active;
} Owner;

extern void fn_8006C9D4(void *entry, s32 value);
extern void fn_8006C9E4(void *entry, s32 value);
extern void fn_8006CAC4(void *entry, s32 value);
extern void fn_8006CAB8(void *entry, s32 value);

s32 fn_8006D12C(Owner *owner, void *entry)
{
    fn_8006C9D4(entry, 5);
    fn_8006C9E4(entry, 0);
    fn_8006CAC4(entry, 500);
    fn_8006CAB8(entry, 0);
    owner->active = entry;
    return 1;
}
