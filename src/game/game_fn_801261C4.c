typedef unsigned char u8;

typedef struct Owner {
    u8 pad[0x3C];
    void* header;
} Owner;

extern void fn_8012BE94(Owner*, void*);

void fn_801261C4(Owner* owner)
{
    fn_8012BE94(owner, owner->header);
}
