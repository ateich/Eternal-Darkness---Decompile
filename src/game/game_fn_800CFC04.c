typedef signed short s16;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct Entry {
    s16 id;
    u16 value2;
    u16 value4;
    u16 value6;
} Entry;

extern Entry lbl_805FAA60[10];
extern u8 lbl_80300368[];

extern void *memcpy(void *, const void *, unsigned long);
extern void *memset(void *, int, unsigned long);
extern void fn_8011E918(void *);

void fn_800CFC04(void *state, Entry *entries, void *stream)
{
    Entry *global;
    Entry *entry;
    int i;

    memcpy(state, lbl_80300368, 0x44);
    memset(lbl_80300368, 0, 0x44);
    entry = entries;
    global = lbl_805FAA60;
    i = 0;
    while (i < 10) {
        if (global->value6 == 0 && global->value4 == 0) {
            memcpy(entry, global, sizeof(Entry));
            memset(global, 0, sizeof(Entry));
        }
        i++;
        entry++;
        global++;
    }
    fn_8011E918(stream);
}
