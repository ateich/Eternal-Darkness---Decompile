typedef unsigned int u32;

typedef struct CodecEntry {
    void *unk0;
    void *model;
    char pad8[0x18];
    void *actor;
    void *owner;
    int unk28;
} Slot;

/* Retain the previous primary and shadow slots while rebuilding the menu. */
typedef struct SlotTable {
    Slot previous[6];
    Slot current[6];
    Slot previousShadow[6];
    Slot shadow[6];
    Slot extra[32];
    void *lists[2];
} SlotTable;

extern unsigned char lbl_80330D80[];
extern unsigned char lbl_80332140[];
extern int lbl_8064CCD0;

extern void *memset(void *, int, unsigned long);
extern void fn_80109FA0(Slot *, void *, int);
extern int fn_801579EC(void *);
extern int fn_801579F4(void *);
extern int fn_80157FE0(void *, u32, int);
extern void *fn_80158598(int, int);
extern void fn_801E8B24(void *, int, int);
extern int fn_801E8D34(void *);
extern unsigned long long fn_8020123C(int, int, int, int);
extern void *fn_80201814(int);
extern int fn_80201B44(void);
extern int fn_80201B54(int *);
extern void *fn_80201B9C(void);
extern void *fn_80201C24(void *);
extern void *fn_80201C2C(void *);
extern void *fn_80204844(void *, int);
extern int fn_80205110(void *);
extern int fn_80205134(void *);
extern void *fn_802051A4(void *);

int fn_8010A32C(int first, int start, int end)
{
    SlotTable *table = (SlotTable *)lbl_80330D80;
    Slot *current;
    Slot *previous;
    Slot *shadow;
    Slot *previousShadow;
    Slot *fillShadow;
    Slot *shadowSource;
    void *group;
    void *iter;
    void *object;
    void *owner;
    void *actor;
    int actorId;
    int count;
    int index;
    int slot;
    int i;
    int j;

    fillShadow = table->shadow;
    group = fn_80201814(fn_80201B44());
    count = fn_80205110(group);
    shadowSource = table->shadow;

    current = ((SlotTable *)lbl_80330D80)->current;
    previous = table->previous;
    shadow = table->shadow;
    /* The shadow snapshot follows the two primary banks. */
    previousShadow = (Slot *)((char *)lbl_80330D80 + 0x210);
    lbl_8064CCD0 = 4;
    for (i = 0; i < 6; i++) {
        previous[i] = current[i];
        previousShadow[i] = shadowSource[i];
    }
    memset(current, 0, sizeof(table->current));
    memset(table->extra, 0, sizeof(table->extra));
    memset(shadow, 0, sizeof(table->shadow));
    count = 0 > count ? 0 : count;

    if (*(u32 *)(lbl_80332140 + 0x10) & 2) {
        if (count != 0) {
            return 0;
        }
        object = fn_80204844(fn_80201B9C(), 0x20);
        *(u32 *)(lbl_80332140 + 0x10) &= ~2u;
        if (object != 0) {
            fn_8020123C(0x52, 0, fn_80201B54(object), 0);
        }
    }

    if ((actorId = fn_80157FE0(fn_80158598(fn_80201B44(), 0), 2, 0)) > 0) {
        actor = fn_80201814(actorId);
        if (actor != 0) {
            fn_80109FA0(&table->extra[0], actor, -1);
        }
    }
    if ((actorId = fn_80157FE0(fn_80158598(fn_80201B44(), 0), 1, 0)) > 0 &&
        (actor = fn_80201814(actorId)) != 0) {
        fn_80109FA0(&table->extra[1], actor, -1);
    }
    if ((actorId = fn_80157FE0(fn_80158598(fn_80201B44(), 0), 4, 0)) > 0 &&
        (actor = fn_80201814(actorId)) != 0) {
        fn_80109FA0(&table->extra[2], actor, -2);
    }

    index = 0;
    for (iter = fn_802051A4(fn_80201C2C(group)); iter != 0;
         iter = fn_802051A4(iter), index++) {
        object = fn_80201814(fn_80205134(iter));
        if (object != 0) {
            owner = fn_80201C24(object);
            if (fn_801579EC(owner) == 0) {
                slot = index - first;
                if (slot >= start && slot < end) {
                    if ((actorId = fn_801579F4(owner)) != 0) {
                        fn_80109FA0(&current[slot], fn_80201814(actorId), slot - start);
                        fn_80109FA0(&fillShadow[slot], object, slot - start);
                    } else {
                        fn_80109FA0(&current[slot], object, slot - start);
                    }
                }
            } else {
                index--;
                count--;
            }
        }
    }

    for (i = 0; i < 6; i++) {
        if (current[i].owner != 0) {
            for (j = 0; j < 6; j++) {
                if (current[i].actor == previous[j].actor) {
                    current[i].unk0 = previous[j].unk0;
                    break;
                }
            }
        }
    }

    if (table->lists[0] != 0 && table->lists[1] != 0) {
        if (fn_801E8D34(table->lists[1]) * 2 + fn_801E8D34(table->lists[0]) >= count) {
            fn_801E8B24(table->lists[0], 0, 0);
            fn_801E8B24(table->lists[1], 0, 0);
        }
    }
    return count;
}
