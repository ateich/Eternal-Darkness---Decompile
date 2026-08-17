extern void* fn_80156938(void*);
extern int fn_801800F8(void*);
extern int fn_80180170(void*, unsigned char);
extern int fn_8017FED4(void*);
extern int fn_80180114(void*);
extern void fn_80185008(void*, void*);
extern void fn_801850E4(void*);
extern void fn_801850CC(void*);

typedef struct InstanceList {
    unsigned char count;
    unsigned char pad1[5];
    unsigned short state;
    unsigned char flags[0x80];
    void* instances[1];
} InstanceList;

void fn_80148D08(void* object, void* other)
{
    int i;
    unsigned char* current;
    int count;
    InstanceList* list;
    void* instance;

    list = fn_80156938(object);
    instance = fn_80156938(other);
    count = list->count;

    if (fn_801800F8(instance)) {
        current = (unsigned char*)list;
        i = 0;
        for (; i < count; current += 4, i++) {
            if (*(void**)(current + 0x88) != 0) {
                fn_80185008(*(void**)(current + 0x88), instance);
                if (fn_80180170(instance, *(unsigned int*)(current + 8)) ||
                    fn_8017FED4(instance))
                    fn_801850E4(*(void**)(current + 0x88));
            }
        }
        list->state = 2;
    }

    if (fn_80180114(instance)) {
        list->state = 1;
        current = (unsigned char*)list;
        i = 0;
        for (; i < count; current += 4, i++) {
            if (*(void**)(current + 0x88) != 0)
                fn_801850CC(*(void**)(current + 0x88));
        }
    }
}
