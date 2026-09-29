typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Record {
    char pad00[0x48];
    u32 flags;
} Record;

typedef struct RecordSet {
    char pad00[0x34];
    u16 count;
    char pad36[2];
    Record* records;
} RecordSet;

extern RecordSet* fn_8015C390(int);

Record* fn_80158C0C(int index, int key)
{
    Record* result = 0;
    RecordSet* set;
    Record* records;
    Record* record;
    int i;

    if (index != -1) {
        set = fn_8015C390(key);
        if (set != 0 && set->count != 0) {
            records = set->records;
            record = records;
            if (index >= 0 && index < set->count) {
                result = &records[index];
            } else if (index == -2) {
                for (i = 0; i < set->count; i++, record++) {
                    if (record->flags & 0x10) {
                        result = record;
                        break;
                    }
                }
                if (result == 0) {
                    result = records;
                }
            }
        }
    }
    return result;
}
