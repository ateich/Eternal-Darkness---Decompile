typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct PointEntry {
    unsigned char pad_0[0x28];
    u32 kind;
    s16 x;
    s16 y;
    s16 z;
    unsigned char pad_32[2];
    u32 value;
    unsigned char pad_38[0x10];
    u32 mask;
} PointEntry;

typedef struct PointTable {
    unsigned char pad_0[0x34];
    u16 count;
    unsigned char pad_36[2];
    PointEntry entries[1];
} PointTable;

extern PointTable *fn_8015C390(s32 table_kind);
extern unsigned int fn_800FBFB0(void);
#define fn_800FBFB0() ((int)fn_800FBFB0())
extern u32 fn_80178F14(s32 ax, s32 ay, s32 az, s32 bx, s32 by, s32 bz);

static void copy_point(PointEntry *entry, Vec3 *position, u32 *value, u32 *kind)
{
    position->x = entry->x;
    position->y = entry->y;
    position->z = entry->z;
    if (value != 0) {
        *value = entry->value;
    }
    if (kind != 0) {
        *kind = entry->kind;
    }
}

s32 fn_8006D548(s32 table_kind, u32 mask, u32 mode, Vec3 *position,
                 u32 *value, u32 *kind, s32 start)
{
    PointTable *table;
    PointEntry *entry;
    s32 selected = -1;
    s32 candidates[100];
    s32 count = 0;
    s32 i;

    table = fn_8015C390(table_kind);
    if (table == 0 || table->count == 0 || mode > 7) {
        return -1;
    }

    if (mode == 1) {
        if (start >= 0 && start < table->count) {
            entry = &table->entries[start];
            if ((entry->mask & mask) != 0) {
                copy_point(entry, position, value, kind);
                selected = start;
            }
        }
    } else if (mode == 2) {
        for (i = 0; i < table->count && count < 100; i++) {
            if ((table->entries[i].mask & mask) != 0) {
                candidates[count++] = (unsigned char)i;
            }
        }
        if (count != 0) {
            selected = candidates[fn_800FBFB0() % count];
            copy_point(&table->entries[selected], position, value, kind);
        }
    } else if (mode == 3) {
        for (i = start; i >= 0 && i < table->count; i++) {
            entry = &table->entries[i];
            if ((entry->mask & mask) != 0) {
                copy_point(entry, position, value, kind);
                selected = i;
                break;
            }
        }
    } else if (mode == 4) {
        u32 best = 10000;
        for (i = 0; i < table->count; i++) {
            u32 distance;
            entry = &table->entries[i];
            if ((entry->mask & mask) == 0) {
                continue;
            }
            distance = fn_80178F14(entry->x, entry->y, entry->z,
                                   (s32)position->x, (s32)position->y,
                                   (s32)position->z);
            if (distance < best) {
                best = distance;
                selected = i;
            }
        }
        if (selected >= 0) {
            copy_point(&table->entries[selected], position, value, kind);
        }
    }
    return selected;
}
