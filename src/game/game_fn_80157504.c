typedef unsigned int u32;

typedef struct Entry {
    u32 index;
    void* payload;
    char pad08[0x1C];
    char storage[1];
} Entry;

extern void* fn_801E8660(u32);
extern u32 fn_801E88E4(void*);
extern void* fn_801E880C(void*, u32, u32);
extern Entry* fn_80157688(int, int);
extern void* fn_801FEA8C(u32, u32, const char*, u32);
extern void* fn_8017CCD8(void*, u32, u32);

extern void* lbl_8064D100;
extern void* lbl_8064D104;
extern void* lbl_8064D108;
extern void* lbl_8064D10C;
extern void* lbl_8064D110;
extern const char lbl_8024F028[];

void fn_80157504(u32 first, u32 second, u32 third)
{
    void* second_allocation;
    void* first_allocation;
    u32 count;
    u32 i;
    Entry* entry;

    lbl_8064D100 = fn_801E8660(first);
    lbl_8064D104 = fn_801E8660(second);
    lbl_8064D108 = fn_801E8660(third);

    count = fn_801E88E4(lbl_8064D100);
    for (i = 0; i < count; i++) {
        entry = fn_80157688(i, 0);
        entry->payload = entry->storage;
        if (entry->index < (u32)lbl_8064D108) {
            entry->index = (u32)fn_801E880C(lbl_8064D108, entry->index, 0);
        }
    }

    first_allocation = fn_801FEA8C(8800, 1, lbl_8024F028, 100);
    second_allocation = fn_801FEA8C(2800, 1, lbl_8024F028, 101);
    lbl_8064D10C = fn_8017CCD8(first_allocation, 88, 100);
    lbl_8064D110 = fn_8017CCD8(second_allocation, 28, 100);
}
