typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

#pragma use_lmw_stmw on

typedef struct Vec3f { float x, y, z; } Vec3f;
typedef struct Entry {
    u8 pad0[0x2C];
    s16 x, y, z;
    u32 metric;
    u8 pad38[0x10];
    u32 flags;
} Entry;
typedef struct Entries {
    u8 pad0[0x34];
    u16 count;
    u8 pad36[2];
    Entry *items;
} Entries;

extern Vec3f lbl_802398F8;
extern Entries *fn_8015C390(int);
extern void fn_8012B690(void *, Vec3f *, Vec3f *);
extern u32 fn_80178F14(int, int, int, int, int, int);

int fn_800CB760(void *object, int collection, u32 mask, Vec3f *output)
{
    Entries *entries;
    int result = 0;
    u8 matches = 0;
    u32 closest = 300000;
    Entry *selected = 0;
    int i;
    Entry *entry;
    Vec3f transformed;
    Vec3f origin;

    entries = fn_8015C390(collection);
    if (entries != 0 && entries->count != 0) {
        entry = entries->items;
        for (i = 0; i < entries->count; i++, entry++) {
            if ((entry->flags & mask) != 0) {
                u32 distance;
                origin = lbl_802398F8;
                fn_8012B690(object, &origin, &transformed);
                distance = fn_80178F14(entry->x, entry->y, entry->z,
                                      (int)transformed.x, (int)transformed.y,
                                      (int)transformed.z);
                if (distance <= entry->metric) {
                    if (entry->metric < closest) {
                        closest = entry->metric;
                        selected = entry;
                    }
                    matches++;
                }
            }
        }
    }
    if (matches >= 1 && selected != 0) {
        result = 1;
        output->x = selected->x;
        output->y = selected->y;
        output->z = selected->z;
    }
    return result;
}
