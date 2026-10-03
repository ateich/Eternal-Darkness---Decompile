typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

#define OFFSETOF(type, member) ((u32)&((type*)0)->member)

typedef struct Definition {
    u32 id;
    u16 kind;
    u16 item_count;
    u16* items;
    s8 child_0;
    s8 child_1;
    u16 runtime_index;
    u8 pad_10[8];
} Definition;

typedef struct Header {
    u8 pad_0[0xE0];
    int definition_count;
    Definition* definitions;
} Header;

typedef struct Slot {
    u32 value;
    u16 flags;
    u16 pad_6;
} Slot;

typedef struct StateEntry {
    u32 id;
    Definition* definition;
    u16 kind;
    u8 pad_A[0x86];
} StateEntry;

/* This is the exact completed type established by the matching caller. */
typedef struct Owner {
    u8 pad[0x3C];
    void* header;
} Owner;

/* Internal layout view; it makes no additional promise about Owner's type. */
typedef struct OwnerLayout {
    u8 pad_0[0x17C];
    Slot slots[24];
    StateEntry* states;
    StateEntry** state_by_id;
    u8 pad_244[0x10];
    int flags;
} OwnerLayout;

typedef char Definition_size_is_0x18[(sizeof(Definition) == 0x18) ? 1 : -1];
typedef char Header_size_is_0xE8[(sizeof(Header) == 0xE8) ? 1 : -1];
typedef char Slot_size_is_8[(sizeof(Slot) == 8) ? 1 : -1];
typedef char StateEntry_size_is_0x90[(sizeof(StateEntry) == 0x90) ? 1 : -1];
typedef char Owner_size_is_0x40[(sizeof(Owner) == 0x40) ? 1 : -1];
typedef char OwnerLayout_size_is_0x258[(sizeof(OwnerLayout) == 0x258) ? 1 : -1];
typedef char Definition_id_is_0[(OFFSETOF(Definition, id) == 0) ? 1 : -1];
typedef char Definition_kind_is_4[(OFFSETOF(Definition, kind) == 4) ? 1 : -1];
typedef char Definition_item_count_is_6[(OFFSETOF(Definition, item_count) == 6) ? 1 : -1];
typedef char Definition_items_is_8[(OFFSETOF(Definition, items) == 8) ? 1 : -1];
typedef char Definition_child_0_is_C[(OFFSETOF(Definition, child_0) == 0xC) ? 1 : -1];
typedef char Definition_child_1_is_D[(OFFSETOF(Definition, child_1) == 0xD) ? 1 : -1];
typedef char Header_definition_count_is_E0[(OFFSETOF(Header, definition_count) == 0xE0) ? 1 : -1];
typedef char Header_definitions_is_E4[(OFFSETOF(Header, definitions) == 0xE4) ? 1 : -1];
typedef char Slot_flags_is_4[(OFFSETOF(Slot, flags) == 4) ? 1 : -1];
typedef char StateEntry_definition_is_4[(OFFSETOF(StateEntry, definition) == 4) ? 1 : -1];
typedef char StateEntry_kind_is_8[(OFFSETOF(StateEntry, kind) == 8) ? 1 : -1];
typedef char Owner_header_is_3C[(OFFSETOF(Owner, header) == 0x3C) ? 1 : -1];
typedef char OwnerLayout_slots_is_17C[(OFFSETOF(OwnerLayout, slots) == 0x17C) ? 1 : -1];
typedef char OwnerLayout_states_is_23C[(OFFSETOF(OwnerLayout, states) == 0x23C) ? 1 : -1];
typedef char OwnerLayout_state_by_id_is_240[(OFFSETOF(OwnerLayout, state_by_id) == 0x240) ? 1 : -1];
typedef char OwnerLayout_flags_is_254[(OFFSETOF(OwnerLayout, flags) == 0x254) ? 1 : -1];

void fn_8012BE94(Owner* owner, void* header_ptr)
{
    Header* header = (Header*)header_ptr;
    OwnerLayout* layout = (OwnerLayout*)owner;
    int i;
    Definition* definition;
    int j;
    u16 item;

    for (i = 0; i < header->definition_count; i++) {
        definition = &header->definitions[i];
        layout->states[i].id = definition->id;
        layout->states[i].definition = definition;
        layout->states[i].kind = definition->kind;
        layout->state_by_id[definition->id] = &layout->states[i];

        for (j = 0; j < definition->item_count; j++) {
            item = definition->items[j];
            if ((item & 0x8000) == 0) {
                if (layout->states[i].kind == 1) {
                    layout->slots[item].flags = 1;
                } else {
                    layout->slots[item].flags = 0;
                }
            }
        }
        if (definition->child_0 != -1) {
            layout->slots[definition->child_0].flags &= ~1;
        }
        if (definition->child_1 != -1) {
            layout->slots[definition->child_1].flags &= ~1;
        }
    }
    layout->flags |= 0x800000;
}
