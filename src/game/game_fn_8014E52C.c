typedef unsigned char u8;

typedef struct Coord3 {
    short x, y, z;
} Coord3;

typedef struct InstanceList {
    u8 count;
    u8 pad1[5];
    unsigned short state;
    u8 entries[0x80];
    void* linked;
} InstanceList;

extern InstanceList* fn_80156938(void*);
extern int fn_80157034(void*);
extern int fn_801800F8(void*);
extern int fn_80180114(void*);
extern int fn_80180130(void*);
extern int fn_80180138(void*, u8);
extern int fn_8018015C(void*, u8);
extern Coord3* fn_8017FDA8(void*, int);
extern void fn_8017FF40();
extern int fn_8019CE08(void*, u8, int);
extern void fn_8019CE1C(void*, u8, int);
extern void fn_8019CE34(void*, u8);
extern int fn_8019CE64(void*);
extern int fn_8019CE6C(void*);
extern int fn_8019CE74(void*);
extern void fn_8019CE7C(void*, int, int, int);

void fn_8014E52C(void* object, void* other)
{
    int count;
    int i;
    int special;
    InstanceList* list;
    void* instance;
    Coord3 position;

    special = 0;
    list = fn_80156938(object);
    instance = fn_80156938(other);

    if (fn_80157034(other))
        special = 1;

    if (fn_801800F8(instance) && !special) {
        fn_80180130(instance);
        if (list->linked != 0) {
            count = fn_80180130(list->linked);
            if (fn_8019CE08(list->linked, 0, 4)) {
                fn_8019CE7C(list->linked,
                            fn_8019CE64(instance),
                            fn_8019CE6C(instance),
                            fn_8019CE74(instance));
                fn_8019CE1C(list->linked, 0, 4);
            }

            count &= 0xFF;
            for (i = 0; i < count; i++) {
                if (fn_80180138(instance, (u8)i) &&
                    fn_8019CE08(instance, (u8)i, 2) &&
                    !fn_8018015C(list->linked, (u8)i)) {
                    Coord3* destination;

                    fn_8019CE34(list->linked, (u8)i);
                    {
                        u8 index = i;
                        fn_8017FF40(instance, index, &position);
                    }
                    destination = fn_8017FDA8(list->linked, i);
                    destination->x = position.x;
                    destination->y = position.y;
                    destination->z = position.z;
                }
            }
        }
        list->state = 2;
    }

    fn_80180114(instance);
}
