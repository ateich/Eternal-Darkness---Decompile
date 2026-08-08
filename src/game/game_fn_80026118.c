typedef unsigned int u32;
typedef int s32;

typedef struct BatchEntry {
    u32 words[110];
} BatchEntry;

extern BatchEntry lbl_803028B0[10];
extern s32 lbl_8064C6EC;

s32 fn_80026118(BatchEntry* entry)
{
    if (entry != 0 && lbl_8064C6EC < 10) {
        lbl_803028B0[lbl_8064C6EC] = *entry;
        lbl_8064C6EC++;
        return 1;
    }

    return 0;
}
