typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Graph {
    u8 pad0[6];
    u16 count;
    u16* entries;
} Graph;

typedef struct Part {
    u8 pad0[4];
    Graph* graph;
} Part;

typedef struct State {
    Part* inherited;
    u16 flags;
    u16 pad;
} State;

typedef struct Context {
    u8 pad0[0x17C];
    State state[24];
    u8 pad23C[4];
    Part** parts;
} Context;

extern void fn_80125ECC(void *);

void fn_8012FB50(Context* context, int index)
{
    Part* part;
    int i;
    u16 entry;

    fn_80125ECC(context);
    part = context->parts[index];
    if (part != 0) {
        Graph* graph = part->graph;

        for (i = 0; i < graph->count; i++) {
            entry = graph->entries[i];
            if (!(entry & 0x8000)) {
                context->state[entry].flags |= 2;
            }
        }
    } else if (index == -1) {
        asm { nop }
    }
}
