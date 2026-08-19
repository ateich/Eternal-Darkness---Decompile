typedef unsigned short u16;

typedef struct Record {
    char pad00[0x58];
    u16 count;
    char pad5A[2];
    void* data;
} Record;

extern Record* fn_8015C390(int);

void* fn_80158950(int key, u16* count)
{
    Record* record = fn_8015C390(key);
    void* data = 0;

    if (record != 0) {
        if (count != 0) {
            *count = record->count;
        }
        data = record->data;
    } else {
        *count = 0;
    }
    return data;
}
