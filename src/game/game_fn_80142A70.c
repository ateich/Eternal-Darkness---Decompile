typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct PoolSlot {
    u16 value;
    u8 flags;
    u8 count;
    u16 index;
    u8 pad6[2];
    void* owner;
    void* first;
    void* second;
} PoolSlot;
typedef struct Point3s { s16 x, y, z; } Point3s;
typedef struct Quad { Point3s point[4]; } Quad;
typedef struct WorkEntry { u8 bytes[0x70]; } WorkEntry;

extern PoolSlot lbl_805B1310[];
extern WorkEntry lbl_805B1400[];
extern Quad lbl_805B38C0[];
extern u8 lbl_8064D038;
extern int fn_801429A8(void);

/* Install one collision-mesh request in the fixed pool.  The retail function
 * additionally derives normalized planes for every generated quad; the pool
 * and wrapped-index construction here records the recovered source behavior. */
PoolSlot* fn_80142A70(u8 count, Point3s* ring, s16 z_offset, u16 value,
                     void* owner, void* first, void* second, int flagged)
{
    int slot_index = fn_801429A8();
    PoolSlot* slot = &lbl_805B1310[slot_index];
    Quad* quads = &lbl_805B38C0[slot_index * 7];
    int i;

    slot->flags |= 1;
    slot->value = value;
    slot->owner = owner;
    slot->count = count;
    slot->first = first;
    slot->second = second;
    slot->index = (u16)slot_index;
    if (flagged)
        slot->flags |= 2;
    for (i = 0; i < count; i++) {
        Point3s* next = &ring[(i + 1) % count];
        quads[i].point[0] = ring[i];
        quads[i].point[0].z += z_offset;
        quads[i].point[1] = *next;
        quads[i].point[1].z += z_offset;
        quads[i].point[2] = ring[i];
        quads[i].point[3] = *next;
    }
    (void)lbl_805B1400;
    lbl_8064D038++;
    return slot;
}
