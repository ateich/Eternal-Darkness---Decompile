typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Buffer {
    char pad0[0x120];
    u8* data;
    char pad124[4];
    void* aux_a;
    void* aux_b;
    char pad130[0x8010];
    short id;
    u8 pad8142[6];
} Buffer;

typedef struct Saved {
    Buffer* buffer;
    void* aux_a;
    void* aux_b;
} Saved;

typedef struct Shared {
    int primary;
    int secondary;
    short requested;
    u8 padA[2];
    Buffer* slots[2];
    void* queues[2];
} Shared;

typedef struct Slot {
    short id;
    short state;
    u8 pad04[8];
    int counter;
    u32 start;
    u32 size;
} Slot;

extern volatile Shared lbl_805B6FE0;
extern Slot lbl_805B6F80[4];
extern u8* lbl_8064D168;
extern int lbl_8064D17C;
extern int lbl_8064D178;
extern int lbl_8064D144;
extern char lbl_8024F038[];

extern int fn_800460FC(void);
extern int fn_800460F4(void);
extern void* fn_801FEA8C(int, int, char*, int);
extern void* memset(void*, int, unsigned int);

void fn_801599BC(int reuse, int clear)
{
    Saved saved[2];
    int count = fn_800460FC();
    int i;

    if (reuse == 1) {
        for (i = 0; i < count; i++) {
            saved[i].buffer = lbl_805B6FE0.slots[i];
            saved[i].aux_a = lbl_805B6FE0.slots[i]->aux_a;
            saved[i].aux_b = lbl_805B6FE0.slots[i]->aux_b;
        }
    }
    if (clear == 1) {
        memset((void*)&lbl_805B6FE0, 0, sizeof(Shared));
    }
    if (count == 1) {
        lbl_805B6FE0.secondary = -1;
    } else {
        lbl_805B6FE0.secondary = lbl_805B6FE0.primary ^ 1;
    }
    lbl_805B6FE0.requested = -1;

    for (i = 0; i < count; i++) {
        if (reuse == 0) {
            lbl_805B6FE0.slots[i] = fn_801FEA8C(sizeof(Buffer), 1, lbl_8024F038, 0x761);
            memset(lbl_805B6FE0.slots[i], 0, sizeof(Buffer));
            lbl_805B6FE0.slots[i]->aux_a = fn_801FEA8C(0xC360, 1, lbl_8024F038, 0x763);
            lbl_805B6FE0.slots[i]->aux_b = fn_801FEA8C(0xC360, 1, lbl_8024F038, 0x764);
        } else {
            lbl_805B6FE0.slots[i] = saved[i].buffer;
            if (clear == 1) {
                memset(lbl_805B6FE0.slots[i], 0, sizeof(Buffer));
            }
            lbl_805B6FE0.slots[i]->aux_a = saved[i].aux_a;
            lbl_805B6FE0.slots[i]->aux_b = saved[i].aux_b;
        }
        if (clear == 1) {
            lbl_805B6FE0.slots[i]->id = -1;
            lbl_805B6FE0.slots[i]->data = (&lbl_8064D168)[i];
        }
    }

    if (clear != 0) {
        Slot* entry;
        int offset;
        lbl_8064D17C = fn_800460F4();
        memset(lbl_805B6F80, 0, sizeof(lbl_805B6F80));
        entry = lbl_805B6F80;
        for (i = 0, offset = 0x600000; i < 4; i++, offset += 0x199A00) {
            entry->start = offset;
            entry->id = -1;
            entry->counter = 5;
            entry->size = 0x199A00;
            entry++;
        }
        lbl_8064D178 = lbl_8064D17C;
        if (lbl_8064D178 < 4) {
            Slot* last = &lbl_805B6F80[lbl_8064D178];
            last->counter = -1;
            last->size = 0xDBCAA0 - last->start;
        }
    }
    lbl_8064D144 = 0;
}
