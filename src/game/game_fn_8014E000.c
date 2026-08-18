typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Coord3 {
    short x, y, z;
} Coord3;

typedef struct InstanceList {
    u8 count;
    u8 pad1[5];
    unsigned short state;
    u8 entries[1];
} InstanceList;

extern u8 lbl_802FC5BC[];
extern void* lbl_8064C4E0;

extern InstanceList* fn_80156938(void*);
extern int fn_80157034(void*);
extern int fn_801800F8(void*);
extern int fn_80180114(void*);
extern int fn_8018015C(void*, u8);
extern void fn_8017F700(void*, void*, u8);
extern void fn_8017FF04(void*, void*);
extern void fn_8017FF40(void*, u8, Coord3*);
extern void* fn_8017FF68(void*, u8);
extern u32 fn_8017FF7C(void*, u8, int);
extern void fn_80184C7C(void*, Coord3*);
extern void fn_80184C98(void*, Coord3*);
extern void fn_8018504C(void*, Coord3*);
extern void fn_801850CC(void*);
extern void fn_801850E4(void*);
extern void fn_801853F0(void*, u32*, int);
extern int fn_8018549C(void*);
extern int fn_801854A8(void*);
extern int fn_801E79FC(void*, int);

void fn_8014E000(void* object, void* other)
{
    u8* current;
    u8* cleanup;
    u8 index;
    int j;
    int i;
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
                void* result;

                index = *(u32*)(current + 8);

                fn_8017FF40(instance, index, &position);
                position.z += 5;

                if (!fn_8018549C(*(void**)(current + 0x88))) {
                    if (!fn_801854A8(*(void**)(current + 0x88))) {
                        if (fn_801E79FC(lbl_8064C4E0, 749)) {
                            u32 active_value = *(u32*)(lbl_802FC5BC + 0x24);
                            ((u8*)&active_value)[3] = 0xA0;
                            fn_801853F0(*(void**)(current + 0x88), &active_value, 1);
                        } else {
                            u32 inactive_value = fn_8017FF7C(instance, index, 0);
                            ((u8*)&inactive_value)[3] = 0;
                            fn_801853F0(*(void**)(current + 0x88), &inactive_value, 0);
                        }
                    }
                    fn_8018504C(*(void**)(current + 0x88), &position);
                }

                if (fn_8018015C(instance, index)) {
                    result = fn_8017FF68(instance, index);
                    fn_8017FF04(*(void**)(current + 0x88), result);
                    fn_801850E4(*(void**)(current + 0x88));
                }

                fn_8017F700(instance, *(void**)(current + 0x88), index);
                fn_80184C7C(*(void**)(current + 0x88), &position);
                fn_80184C98(*(void**)(current + 0x88), &position);
            }
        }
        list->state = 2;
    }

    if (special || fn_80180114(instance)) {
        list->state = 1;
        cleanup = (u8*)list;
        j = 0;
        for (; j < count; cleanup += 4, j++) {
            if (*(void**)(cleanup + 0x88) != 0)
                fn_801850CC(*(void**)(cleanup + 0x88));
        }
    }
}
