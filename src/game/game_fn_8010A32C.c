typedef unsigned int u32;

typedef struct Slot {
    int value;
    void *object;
    char pad08[0x18];
    void *owner;
    void *actor;
    int unk28;
} Slot;

/* sets[0]/[1] are the previous/current primary slots, sets[2]/[3] the
 * previous/current shadow slots. */
typedef struct SlotTable {
    Slot sets[4][6];
    Slot extra[32];
    void *lists[2];
} SlotTable;

extern SlotTable lbl_80330D80;
extern unsigned char lbl_80332140[];
extern int lbl_8064CCD0;

extern void *memset(void *, int, unsigned long);
extern void fn_80109FA0(Slot *, void *, int);
extern int fn_801579EC(void *);
extern int fn_801579F4(void *);
extern int fn_80157FE0(void *, int, int);
extern void *fn_80158598(int, int);
extern void fn_801E8B24(void *, int, int);
extern int fn_801E8D34(void *);
extern unsigned long long fn_8020123C();
extern void *fn_80201814();
extern int fn_80201B44();
extern int fn_80201B54();
extern void *fn_80201B9C();
extern void *fn_80201C24(void *);
extern void *fn_80201C2C(void *);
extern void *fn_80204844(void *, int);
extern int fn_80205110(void *);
extern void *fn_80205134(void *);
extern void *fn_802051A4(void *);

int fn_8010A32C(int first, int start, int end)
{
    SlotTable *table = &lbl_80330D80;
    void *group;
    void *iter;
    void *object;
    void *owner;
    void *actor;
    int count;
    int index;
    int slot;
    int i;
    int j;

    group = fn_80201814(fn_80201B44());
    count = fn_80205110(group);
    lbl_8064CCD0 = 4;
    for (i = 0; i < 6; i++) {
        table->sets[0][i] = table->sets[1][i];
        table->sets[2][i] = table->sets[3][i];
    }
    memset(table->sets[1], 0, sizeof(table->sets[1]));
    memset(table->extra, 0, sizeof(table->extra));
    memset(table->sets[3], 0, sizeof(table->sets[3]));
    count = 0 > count ? 0 : count;

    if (*(u32 *)(lbl_80332140 + 0x10) & 2) {
        if (count != 0) {
            return 0;
        }
        object = fn_80204844(fn_80201B9C(), 0x20);
        *(u32 *)(lbl_80332140 + 0x10) &= ~2u;
        if (object != 0) {
            fn_8020123C(0x52, 0, fn_80201B54(), 0);
        }
    }

    if (fn_80157FE0(fn_80158598(fn_80201B44(), 0), 2, 0) > 0) {
        actor = fn_80201814();
        if (actor != 0) {
            fn_80109FA0(&table->extra[0], actor, -1);
        }
    }
    if (fn_80157FE0(fn_80158598(fn_80201B44(), 0), 1, 0) > 0 && (actor = fn_80201814()) != 0) {
        fn_80109FA0(&table->extra[1], actor, -1);
    }
    if (fn_80157FE0(fn_80158598(fn_80201B44(), 0), 4, 0) > 0 && (actor = fn_80201814()) != 0) {
        fn_80109FA0(&table->extra[2], actor, -2);
    }

    index = 0;
    for (iter = fn_802051A4(fn_80201C2C(group)); iter != 0; iter = fn_802051A4(iter), index++) {
        object = fn_80201814(fn_80205134(iter));
        if (object != 0) {
            owner = fn_80201C24(object);
            if (fn_801579EC(owner) == 0) {
                slot = index - first;
                if (slot >= start && slot < end) {
                    if (fn_801579F4(owner) != 0) {
                        fn_80109FA0(&table->sets[1][slot], fn_80201814(), slot - start);
                        fn_80109FA0(&table->sets[3][slot], object, slot - start);
                    } else {
                        fn_80109FA0(&table->sets[1][slot], object, slot - start);
                    }
                }
            } else {
                index--;
                count--;
            }
        }
    }

    for (i = 0; i < 6; i++) {
        if (table->sets[1][i].actor != 0) {
            for (j = 0; j < 6; j++) {
                if (table->sets[1][i].owner == table->sets[0][j].owner) {
                    table->sets[1][i].value = table->sets[0][j].value;
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
