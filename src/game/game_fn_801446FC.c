typedef struct Entry {
    int field0;
    int field4;
    void* field8;
    char pad[0x14];
} Entry;

void* fn_801446FC(Entry* base, int index, void* field)
{
    void* old = base[index].field8;
    base[index].field8 = field;
    return old;
}
