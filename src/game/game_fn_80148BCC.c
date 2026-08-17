extern void fn_8017FF40(void*, void*, void*);

typedef struct InstanceList {
    unsigned char pad[0x88];
    void* instances[1];
} InstanceList;

void fn_80148BCC(InstanceList* list, void* first, void* second)
{
    if (list != 0 && list->instances[0] != 0)
        fn_8017FF40(list->instances[0], second, first);
}
