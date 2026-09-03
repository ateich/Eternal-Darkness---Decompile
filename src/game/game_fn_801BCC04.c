typedef unsigned short u16;

typedef struct Bucket {
    u16 count;
    u16 start;
} Bucket;

typedef struct ResourceEntry8 {
    void* value;
    u16 id;
    u16 references;
} ResourceEntry8;

extern unsigned char lbl_8061C748[];
extern u16 lbl_8064D3F8;
extern void fn_801CE2B8(void);
extern void fn_801CE280(void);

int fn_801BCC04(u16 id)
{
    unsigned char* base = lbl_8061C748;
    Bucket* bucket;
    fn_801CE2B8();
    if (((Bucket*)(base + 0x5A00))[id >> 6].count != 0) {
        int bucket_start;
        int bucket_count;
        int index;
        int entry_index;
        int cursor;

        bucket = &((Bucket*)(base + 0x5A00))[id >> 6];
        bucket_start = bucket->start;
        bucket_count = bucket->count;
        index = 0;
        while (index < bucket_count &&
               id != ((ResourceEntry8*)(base + 0x6200))[bucket_start + index].id) {
            index++;
        }
        if (index < bucket_count) {
            entry_index = bucket_start + index;
            if (--((ResourceEntry8*)(base + 0x6200))[entry_index].references == 0) {
                cursor = entry_index + 1;
                bucket_count = lbl_8064D3F8;
                for (; cursor < bucket_count; cursor++) {
                    ((ResourceEntry8*)(base + 0x6200))[cursor - 1] =
                        ((ResourceEntry8*)(base + 0x6200))[cursor];
                }
                for (index = 0; index < 0x200; index++) {
                    if (((Bucket*)(base + 0x5A00))[index].start > bucket_start) {
                        ((Bucket*)(base + 0x5A00))[index].start--;
                    }
                }
                bucket->count--;
                lbl_8064D3F8--;
            }
        }
    }
    fn_801CE280();
    return 0;
}
