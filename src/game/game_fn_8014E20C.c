typedef struct Vec3 {
    short x, y, z;
} Vec3;

typedef struct InstanceList {
    unsigned char count;
    unsigned char pad1[5];
    unsigned short state;
    unsigned char entries[1];
} InstanceList;

extern void *fn_80156938();
extern int fn_80157034(void*);
extern int fn_801800F8(void*);
extern int fn_80180114(void*);
extern int fn_8018015C(void*, unsigned char);
extern void fn_8017FF40(void*, unsigned char, Vec3*);
extern void fn_8018504C(void*, Vec3*);
extern void fn_801850CC(void*);
extern void fn_801850E4(void*);

void fn_8014E20C(void* object, void* other)
{
    int i;
    unsigned char* current;
    int special;
    int count;
    InstanceList* list;
    void* instance;
    Vec3 position;

    special = 0;
    list = fn_80156938(object);
    instance = fn_80156938(other);
    count = list->count;

    if (fn_80157034(other))
        special = 1;

    if (fn_801800F8(instance) && !special) {
        current = (unsigned char*)list;
        i = 0;
        for (; i < count; current += 4, i++) {
            if (*(void**)(current + 0x88) != 0) {
                unsigned char index = *(unsigned int*)(current + 8);
                fn_8017FF40(instance, index, &position);
                fn_8018504C(*(void**)(current + 0x88), &position);
                if (fn_8018015C(instance, index))
                    fn_801850E4(*(void**)(current + 0x88));
            }
        }
        list->state = 2;
    }

    if (fn_80180114(instance) || special) {
        list->state = 1;
        current = (unsigned char*)list;
        i = 0;
        for (; i < count; current += 4, i++) {
            if (*(void**)(current + 0x88) != 0)
                fn_801850CC(*(void**)(current + 0x88));
        }
    }
}
