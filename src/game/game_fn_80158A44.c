typedef unsigned short u16;

typedef struct RecordSet {
    char pad00[0x58];
    u16 count;
    char pad5A[2];
    void* records;
} RecordSet;

extern RecordSet* fn_8015C390(int);

void* fn_80158A44(int index, int key)
{
    void* result = 0;
    RecordSet* set;
    void* records;

    if (index != -1) {
        set = fn_8015C390(key);
        if (set != 0 && set->count != 0) {
            records = set->records;
            if (index >= 0 && index < set->count) {
                result = (char*)records + index * 0x2C;
            }
        }
    }
    return result;
}
