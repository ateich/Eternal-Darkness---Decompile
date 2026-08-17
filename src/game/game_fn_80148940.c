extern void fn_8017FD34(void*);

typedef struct InstanceList {
    unsigned char count;
    unsigned char pad[0x87];
    void* instances[1];
} InstanceList;

void fn_80148940(InstanceList* list)
{
    void* empty = 0;
    unsigned char* current = (unsigned char*)list;
    int count = list->count;
    int i = 0;

    for (; i < count; current += 4, i++) {
        void** slot = (void**)(current + 0x88);
        if (*slot != empty) {
            fn_8017FD34(*slot);
            *slot = empty;
        }
    }
}
