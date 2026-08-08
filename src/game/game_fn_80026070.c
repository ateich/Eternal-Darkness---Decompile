typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

typedef struct QueueEntry {
    u32 words[10];
    u8 pad_28[2];
    u8 active;
    u8 pad_2B;
} QueueEntry;

extern QueueEntry lbl_803026F8[10];
extern s32 lbl_8064C6F0;

s32 fn_80026070(QueueEntry* entry)
{
    if (entry != 0 && lbl_8064C6F0 < 10) {
        if (entry->active == 0) {
            return 0;
        }

        lbl_803026F8[lbl_8064C6F0] = *entry;
        lbl_8064C6F0++;
        return 1;
    }

    return 0;
}
