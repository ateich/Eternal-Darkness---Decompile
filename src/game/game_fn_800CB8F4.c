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

extern Entries *fn_8015C390(int);
extern Vec3f *fn_8011F130(void *);
extern u32 fn_80178F14(int, int, int, int, int, int);
extern u8 fn_8012B8A8(void *, Vec3f *);

int fn_800CB8F4(void *object, int collection, u32 mask, Vec3f *output)
{
    Entries *entries;
    int result = 0;
    u32 closest = 300000;
    int i;
    Entry *selected;
    Entry *entry;
    u32 distance;

    entries = fn_8015C390(collection);
    if (entries != 0 && entries->count != 0) {
        entry = entries->items;
        selected = 0;
        for (i = 0; i < entries->count; i++, entry++) {
            if ((entry->flags & mask) != 0) {
                Vec3f *position = fn_8011F130(object);
                distance = fn_80178F14(entry->x, entry->y, entry->z,
                                      (int)position->x, (int)position->y,
                                      (int)position->z);
                if (distance <= closest) {
                    Vec3f candidate;
                    candidate.x = entry->x;
                    candidate.y = entry->y;
                    candidate.z = entry->z;
                    if (fn_8012B8A8(object, &candidate) != 0) {
                        closest = distance;
                        selected = entry;
                    }
                }
            }
        }
        if (selected != 0) {
            result = 1;
            output->x = selected->x;
            output->y = selected->y;
            output->z = selected->z;
        }
    }
    return result;
}
