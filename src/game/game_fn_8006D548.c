typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned short u16;
typedef unsigned int u32;

/* NonMatching: canonical GC/1.3 reaches 99.25% with the retail 0x950-byte
 * function size and control-flow offsets. Register allocation and compiler-
 * owned conversion-constant / jump-table relocations still differ. */

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
    PointEntry *entries;
} PointTable;

extern PointTable *fn_8015C390(s32 table_kind);
extern unsigned int fn_800FBFB0(void);
#define fn_800FBFB0() ((int)fn_800FBFB0())
extern u32 fn_80178F14(s32 ax, s32 ay, s32 az, s32 bx, s32 by, s32 bz);
extern void fn_8017ACE0(void *matrix, Vec3 *input, Vec3 *output);
extern s32 fn_800AD2B4(void);
extern void *fn_80201890(void);
extern Vec3 *fn_8011F130(void *object);
extern float fn_80211B44(Vec3 *a, Vec3 *b);
extern unsigned char lbl_8063C068[];
extern Vec3 lbl_8063D378;
extern void *lbl_8064C4E4;
extern float lbl_8064E7FC;
extern float lbl_8064E800;
extern float lbl_8064E804;

static inline void copy_point(PointEntry *entry, Vec3 *position, u32 *value, u32 *kind)
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
    s32 i;
    s32 count = 0;
    s32 candidates[100];
    s32 selected = -1;
    PointEntry *entry;
    PointEntry *entries;
    PointTable *table;

    table = fn_8015C390(table_kind);
    if (table == 0) {
        goto done;
    }
    if (table->count == 0) {
        goto done;
    }
    entry = table->entries;
    entries = entry;

    switch (mode) {
    case 2: {
        s32 *candidate = candidates;
        s32 limit = table->count;
        for (i = 0; i < limit; i++, entry++) {
            if (count >= 100) {
                break;
            }
            if ((entry->mask & mask) != 0) {
                *candidate++ = (unsigned char)i;
                count++;
            }
        }
        if (count != 0) {
            s32 pick = candidates[fn_800FBFB0() % count];
            entry = &entries[pick];
            selected = pick;
            copy_point(entry, position, value, kind);
        }
        break;
    }
    case 1: {
        if (start >= 0 && start < table->count) {
            entry = &entries[start];
            if ((entry->mask & mask) != 0) {
                copy_point(entry, position, value, kind);
                selected = start;
            }
        }
        break;
    }
    case 3: {
        /* The initial signed guard is outside the counted forward scan. */
        s32 limit = table->count;
        if (start < 0) {
            break;
        }
        for (i = start; i < limit; i++) {
            entry = &entries[i];
            if ((entry->mask & mask) != 0) {
                copy_point(entry, position, value, kind);
                selected = i;
                break;
            }
        }
        break;
    }
    case 4: {
        u32 best = 10000;
        count = -1;
        for (i = 0; i < table->count; i++, entry++) {
            u32 distance;
            if ((entry->mask & mask) == 0) {
                continue;
            }
            distance = fn_80178F14(entry->x, entry->y, entry->z,
                                   (s32)position->x, (s32)position->y,
                                   (s32)position->z);
            if (distance < best) {
                best = distance;
                count = i;
            }
        }
        if (count >= 0) {
            selected = count;
            entry = &entries[count];
            copy_point(entry, position, value, kind);
        }
        break;
    }
    case 5: {
        Vec3 point;
        Vec3 projected;
        count = -1;
        for (i = 0; i < table->count; i++, entry++) {
            if ((entry->mask & mask) == 0) {
                continue;
            }
            if (fn_80178F14(entry->x, entry->y, entry->z,
                            (s32)lbl_8063D378.x, (s32)lbl_8063D378.y,
                            (s32)lbl_8063D378.z) <= 800) {
                continue;
            }
            point.x = entry->x;
            point.y = entry->y;
            point.z = entry->z;
            fn_8017ACE0(lbl_8063C068, &point, &projected);
            if (projected.x > lbl_8064E7FC && projected.x < lbl_8064E800 &&
                projected.y > lbl_8064E7FC && projected.y < lbl_8064E804) {
                count = i;
                break;
            }
        }
        if (count >= 0) {
            selected = count;
            entry = &entries[count];
            copy_point(entry, position, value, kind);
        }
        break;
    }
    case 6: {
        Vec3 point;
        Vec3 projected;
        if (start >= 0 && start < table->count) {
            entry = &entries[start];
            if ((entry->mask & mask) != 0 &&
                fn_80178F14(entry->x, entry->y, entry->z,
                            (s32)lbl_8063D378.x, (s32)lbl_8063D378.y,
                            (s32)lbl_8063D378.z) > 800) {
                point.x = entry->x;
                point.y = entry->y;
                point.z = entry->z;
                fn_8017ACE0(lbl_8063C068, &point, &projected);
                if (projected.x > lbl_8064E7FC && projected.x < lbl_8064E800 &&
                    projected.y > lbl_8064E7FC && projected.y < lbl_8064E804) {
                    copy_point(entry, position, value, kind);
                    selected = start;
                }
            }
        }
        break;
    }
    case 7: {
        s32 *candidate;
        Vec3 direction;
        Vec3 segment;
        Vec3 *origin;
        Vec3 *camera;

        if (fn_800AD2B4() != 0) {
            origin = fn_8011F130(fn_80201890());
            camera = fn_8011F130(lbl_8064C4E4);
            candidate = candidates;
            segment.x = origin->x - camera->x;
            segment.y = origin->y - camera->y;
            segment.z = origin->z - camera->z;
            for (i = 0; i < table->count; i++, entry++) {
                if ((entry->mask & mask) == 0) {
                    continue;
                }
                direction.x = origin->x - entry->x;
                direction.y = origin->y - entry->y;
                direction.z = origin->z - entry->z;
                if (fn_80211B44(&direction, &segment) < lbl_8064E7FC) {
                    *candidate++ = (unsigned char)i;
                    count++;
                    /* Retail stops immediately after filling the final slot. */
                    if (count == 100) {
                        break;
                    }
                }
            }
            if (count != 0) {
                s32 pick = candidates[fn_800FBFB0() % count];
                entry = &entries[pick];
                selected = pick;
                copy_point(entry, position, value, kind);
            } else {
                selected = fn_8006D548(table_kind, mask, 2, position, value,
                                       kind, start);
            }
        }
        break;
    }
    }
done:
    return selected;
}
