typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Pair { u32 first; u32 second; } Pair;

typedef struct Graph {
    u8 pad0[6];
    u16 count;
    u16* entries;
    s8 slot;
    s8 child_slot;
} Graph;

typedef struct Part {
    u8 pad0[4];
    Graph* graph;
    u16 flags;
    u16 mode;
    u8 padC[0x20];
    u32 value2C;
    u8 pad30[0xC];
    u32 value3C;
    u16 value40;
    u8 pad42[0x12];
    u32 value54;
    u16 value58;
    u8 pad5A[0x12];
    Pair pair;
} Part;

typedef struct State { Part* inherited; u16 flags; u16 pad; } State;

typedef struct Context {
    u8 pad0[0x17C];
    State state[24];
    u8 pad23C[4];
    Part** parts;
    u8 pad244[0x34];
    float value278;
} Context;

extern void fn_80125ECC(void*);
extern void fn_8012BFE4(Context*);
extern void fn_8012C478(Context*, int, int);
extern void fn_8012CAC4(Context*, int, Part*);

void fn_8012C804(Context* dst, Context* src, int index)
{
    int index_offset;
    int i;
    Part* selected;
    Graph* graph;
    Part* part;
    u16 entry;
    Part* inherited;
    Graph* source;

    fn_80125ECC(dst);
    index_offset = index * 4;

    for (i = 0; i < 24; i++) {
        dst->state[i].flags = 0;
        dst->state[i].inherited = 0;
    }

    graph = (*(Part**)((u8*)dst->parts + index_offset))->graph;
    for (i = 0; i < graph->count; i++) {
        entry = graph->entries[i];
        if (entry & 0x8000) {
            int child = entry & ~0x8000;

            part = src->parts[child];
            if (part->flags & 1) {
                fn_8012C478(dst, child, 1);
            } else {
                s8 slot = dst->parts[child]->graph->child_slot;

                if (slot != -1) {
                    dst->state[slot].flags |= 1;
                }
            }
        } else if (src->state[entry].flags & 1) {
            dst->state[entry].flags |= 1;
        }
    }

    {
        s8 slot = graph->slot;

        if (slot != -1) {
            dst->state[slot].flags |= 1;
        }
    }

    for (i = 0; i < 18; i++) {
        part = src->parts[i];
        if (part != 0) {
            selected = dst->parts[i];
            if (part->mode & 0x3F) {
                selected->mode = part->mode;
                selected->value3C = part->value3C;
                selected->value40 = part->value40;
                selected->value54 = part->value54;
                selected->value58 = part->value58;
                selected->pair = part->pair;
            }
        }
    }

    fn_8012BFE4(dst);

    inherited = 0;
    source = src->parts[index]->graph;
    for (i = 0; i < source->count; i++) {
        entry = source->entries[i];
        if (!(entry & 0x8000)) {
            inherited = src->state[entry].inherited;
            break;
        }
    }
    if (inherited != 0) {
        selected->flags = inherited->flags;
        selected->value2C = inherited->value2C;
    }

    fn_8012CAC4(dst, index, selected);
    dst->value278 = src->value278;
}
