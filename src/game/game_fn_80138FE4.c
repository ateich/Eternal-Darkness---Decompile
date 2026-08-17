typedef unsigned short u16;

typedef struct Resource {
    unsigned char pad[0x14];
    u16 count;
} Resource;

typedef struct Slot {
    int resource_id;
    unsigned char pad04[0x3C];
    void* source;
    Resource* resource;
    unsigned int size;
    unsigned char state;
    unsigned char flag;
    unsigned char pad4E[2];
} Slot;

typedef struct State {
    int id;
    int limit;
    unsigned char pad08[0x2B0];
    Slot slots[2];
} State;

extern State lbl_805AE020;
extern char lbl_8024EF1C[];
extern char lbl_8024EF40[];

extern Resource* fn_80125664(void*, int);
extern void fn_8012B408(Resource*, unsigned int);
extern void fn_80155BB0(char*, char*, ...);

void fn_80138FE4(int index, unsigned int size)
{
    Slot* slot = &lbl_805AE020.slots[index];

    slot->resource = fn_80125664(slot->source, 0);
    slot->size = (size + 31) & ~31;
    fn_8012B408(slot->resource, slot->size);
    if (slot->size + ((unsigned int)slot->resource->count << 4) >
        (unsigned int)slot->source + lbl_805AE020.limit) {
        fn_80155BB0(lbl_8024EF1C, lbl_8024EF40);
    }
    slot->state = 2;
    slot->flag = 0;
}
