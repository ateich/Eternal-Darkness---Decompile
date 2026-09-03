typedef unsigned short u16;
typedef unsigned int u32;

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

int fn_801BC8F4(u16 id, void* value)
{
    unsigned char* base = lbl_8061C748;
    u16 bucket_count;
    int bucket_start;
    int index;
    int insertion;
    int cursor;

    fn_801CE2B8();
    bucket_count = ((Bucket*)(base + 0x5A00))[id >> 6].count;

    if (bucket_count == 0) {
        bucket_start = lbl_8064D3F8;
        ((Bucket*)(base + 0x5A00))[id >> 6].start = bucket_start;
        insertion = bucket_start;
    } else {
        bucket_start = ((Bucket*)(base + 0x5A00))[id >> 6].start;
        index = 0;
        while (index < bucket_count &&
               ((ResourceEntry8*)(base + 0x6200))[bucket_start + index].id < id) {
            index++;
        }
        if (index < bucket_count) {
            insertion = bucket_start + index;
            if (((ResourceEntry8*)(base + 0x6200))[insertion].id == id) {
                ((ResourceEntry8*)(base + 0x6200))[insertion].references++;
                fn_801CE280();
                return 0;
            }
        } else {
            insertion = bucket_start + index;
        }
    }

    if ((u32)lbl_8064D3F8 >= 0x800) {
        goto full;
    }

    for (index = 0; index < 0x200; index++) {
        if (((Bucket*)(base + 0x5A00))[index].start > bucket_start) {
            ((Bucket*)(base + 0x5A00))[index].start++;
        }
    }

    for (cursor = lbl_8064D3F8 - 1; cursor >= insertion; cursor--) {
        ((ResourceEntry8*)(base + 0x6200))[cursor + 1] =
            ((ResourceEntry8*)(base + 0x6200))[cursor];
    }

    ((ResourceEntry8*)(base + 0x6200))[insertion].id = id;
    ((ResourceEntry8*)(base + 0x6200))[insertion].value = value;
    ((ResourceEntry8*)(base + 0x6200))[insertion].references = 1;
    ((Bucket*)(base + 0x5A00))[id >> 6].count++;
    lbl_8064D3F8++;
    fn_801CE280();
    return 1;

full:
    fn_801CE280();
    return 0;
}
