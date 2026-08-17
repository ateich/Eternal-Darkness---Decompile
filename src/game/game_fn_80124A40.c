typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;

typedef struct Pair {
    u32 start;
    u32 count;
} Pair;

typedef struct Delta {
    s32 index;
    s16 x, y, z;
    u8 pad[2];
} Delta;

typedef struct Entry {
    u8 pad0[8];
    u16 start;
    u16 count;
    u8 padC[8];
    Pair pairs[32];
    u8 pad114[4];
} Entry;

typedef struct Table {
    u8 pad0[12];
    u16 count;
    u8 padE[26];
    Entry* entries;
    u8 pad2C[8];
    u32 second_output;
    u8 pad38[24];
    u32 first_output;
    u8 pad54[136];
    Delta* deltas;
} Table;

typedef struct Weight {
    float value;
    u8 pad4[32];
    u32 flags;
} Weight;

typedef struct Owner {
    u8 pad0[0x180];
    u16 flags;
    u8 pad182[0x11A];
    Weight* weights;
    u32 enabled;
} Owner;

typedef struct Vertex {
    s16 x, y, z;
} Vertex;

extern Pair lbl_804FA6D0[];
extern Vertex lbl_804FA740[];

void fn_80124A40(Owner* owner, Table* table, u32* first_output,
                 u32* second_output)
{
    s32 entry_index;
    s32 count = table->count;

    *first_output = table->first_output;
    *second_output = table->second_output;

    for (entry_index = 0; entry_index < count; entry_index++) {
        lbl_804FA6D0[entry_index].start = 0;
    }

    for (entry_index = 0; entry_index < count; entry_index++) {
        Entry* entry = &table->entries[entry_index];
        u32 begin = entry->start;
        u32 end = begin + entry->count;
        s32 weight_index;

        if (owner->enabled != 0 && (owner[entry_index].flags & 1)) {
            u32 vertex_index;
            for (vertex_index = begin; vertex_index < end; vertex_index++) {
                lbl_804FA740[vertex_index] =
                    ((Vertex*)table->first_output)[vertex_index];
            }

            for (weight_index = 0; weight_index < 32; weight_index++) {
                Pair* pair = &entry->pairs[weight_index];
                Weight* weight = &owner->weights[weight_index];
                u32 delta_index;

                if ((weight->flags & 1) == 0 || pair->start == 0xFFFFFFFF) {
                    continue;
                }
                lbl_804FA6D0[entry_index].start = 1;
                for (delta_index = pair->start;
                     delta_index < pair->start + pair->count; delta_index++) {
                    Delta* delta = &table->deltas[delta_index];
                    Vertex* vertex = &lbl_804FA740[entry->start + delta->index];
                    vertex->x += (s32)(weight->value * delta->x);
                    vertex->y += (s32)(weight->value * delta->y);
                    vertex->z += (s32)(weight->value * delta->z);
                }
            }
        }
    }
}
