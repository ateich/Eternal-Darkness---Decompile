typedef signed int s32;
typedef unsigned char u8;

typedef struct Owner {
    char pad0[0x15];
    u8 kind;
    char pad16[0x22];
    s32 value;
} Owner;

extern s32 fn_8006BCB4(Owner *owner);
extern void fn_80071AD4(s32 resource, s32 kind, s32 value);

void fn_8006BD40(Owner *owner)
{
    fn_80071AD4(fn_8006BCB4(owner), owner->kind, owner->value);
}
