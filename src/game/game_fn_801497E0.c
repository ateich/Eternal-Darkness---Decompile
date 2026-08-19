extern void *fn_80156938();
extern void* fn_8017FDE4(void*);
extern int fn_80201B54();
extern int fn_800AD2B4(void);
extern int fn_800AD538(void);
extern void fn_801499C4(void*, void*, void*, void*, int);

typedef struct InstanceList {
    unsigned char count;
    unsigned char pad[7];
    void* firstData;
    unsigned char pad2[0x3C];
    void* secondData;
    unsigned char pad3[0x3C];
    void* instances[1];
} InstanceList;

void fn_801497E0(void* object, void* other)
{
    int identifier;
    unsigned char* current;
    int i;
    int count;
    void* instance;
    InstanceList* list;

    identifier = 0;
    instance = fn_80156938(other);
    list = fn_80156938(object);
    count = list->count;
    if (instance != 0) {
        identifier = fn_80201B54(instance);
    }
    if (fn_800AD2B4() == 0 || identifier != fn_800AD538()) {
        current = (unsigned char*)list;
        i = 0;
        for (; i < count; current += 4, i++) {
            void* value = fn_8017FDE4(*(void**)(current + 0x88));
            fn_801499C4(instance, value, *(void**)(current + 8),
                        *(void**)(current + 0x48), 0);
        }
    }
}
