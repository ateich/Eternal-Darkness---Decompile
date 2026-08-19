typedef unsigned char u8;

typedef struct Coord3 {
    short x, y, z;
} Coord3;

typedef struct InstanceList {
    u8 count;
    u8 pad1[5];
    unsigned short state;
    u8 entries[1];
} InstanceList;

extern void *fn_80156938();
extern int fn_80157034(void*);
extern int fn_801800F8(void*);
extern int fn_80180114(void*);
extern int fn_80180138(void*, u8);
extern int fn_8018015C(void*, u8);
extern void fn_8017F700(void*, void*, u8);
extern void fn_8017FF40(void*, int, Coord3*);
extern void fn_80184C7C(void*, Coord3*);
extern void fn_80184C98(void*, Coord3*);
extern void fn_80185008(void*, void*);
extern void fn_801850CC(void*);
extern void fn_801850E4(void*);
extern int fn_8019CE08(void*, u8, int);

void fn_8014E33C(void* object, void* other)
{
    int i;
    u8* current;
    int special;
    int count;
    InstanceList* list;
    void* instance;
    Coord3 position;

    special = 0;
    list = fn_80156938(object);
    instance = fn_80156938(other);
    count = list->count;

    if (fn_80157034(other))
        special = 1;

    if (fn_801800F8(instance) && !special) {
        current = (u8*)list;
        i = 0;
        for (; i < count; current += 4, i++) {
            if (*(void**)(current + 0x88) != 0) {
                if (fn_80180138(instance, (u8)i)) {
                    fn_80185008(*(void**)(current + 0x88), instance);
                    if (fn_8018015C(instance, (u8)i))
                        fn_801850E4(*(void**)(current + 0x88));
                    fn_8017F700(instance, *(void**)(current + 0x88), (u8)i);
                    fn_8017FF40(instance, i, &position);
                    fn_80184C7C(*(void**)(current + 0x88), &position);
                    fn_80184C98(*(void**)(current + 0x88), &position);
                }
                if (fn_8019CE08(instance, (u8)i, 2))
                    fn_801850CC(*(void**)(current + 0x88));
            }
        }
        list->state = 2;
    }

    if (fn_80180114(instance) || special) {
        list->state = 1;
        current = (u8*)list;
        i = 0;
        for (; i < count; current += 4, i++) {
            if (*(void**)(current + 0x88) != 0)
                fn_801850CC(*(void**)(current + 0x88));
        }
    }
}
