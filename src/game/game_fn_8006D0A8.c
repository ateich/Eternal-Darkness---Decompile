typedef signed int s32;
typedef unsigned char u8;

typedef struct Owner {
    void *pad_0;
    void *active;
    unsigned char pad_8[0xD];
    u8 kind;
    unsigned char pad_16[0x22];
    s32 value;
} Owner;

extern s32 fn_80071AD4(void *candidate, u8 kind, s32 value);
extern void *fn_8006D1DC(void *candidate);
extern s32 fn_8006D12C(Owner *owner, void *entry);

s32 fn_8006D0A8(Owner *owner, void *candidate)
{
    s32 result = 0;
    void *entry;

    if (fn_80071AD4(candidate, owner->kind, owner->value) != 0 &&
        owner->active == 0) {
        entry = fn_8006D1DC(candidate);
        fn_8006D12C(owner, entry);
        result = 1;
    }
    return result;
}
