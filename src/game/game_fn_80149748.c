extern void* fn_80156938(void*);
extern void* fn_8017FDE4(void*);
extern void fn_80149B60(void*, void*, void*, void*, int);

typedef struct InstanceList {
    unsigned char count;
    unsigned char pad[7];
    void* firstData;
    unsigned char pad2[0x3C];
    void* secondData;
    unsigned char pad3[0x3C];
    void* instances[1];
} InstanceList;

void fn_80149748(void* object, void* other)
{
    unsigned char* current;
    int count;
    int i;
    void* instance;
    InstanceList* list;

    instance = fn_80156938(other);
    list = fn_80156938(object);
    count = list->count;
    i = 0;
    current = (unsigned char*)list;
    for (; i < count; current += 4, i++) {
        void* value = fn_8017FDE4(*(void**)(current + 0x88));
        fn_80149B60(instance, value, *(void**)(current + 8),
                    *(void**)(current + 0x48), 0);
    }
}
