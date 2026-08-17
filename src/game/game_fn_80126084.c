typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Entry {
    int state;
    u32 pad;
    void* object;
} Entry;

extern Entry lbl_80514AE0[];
extern Entry lbl_8056FA80[];
extern void fn_8011F7E0(void*, int);

/* NonMatching: honest reconstruction of both active-entry teardown scans.
 * Retail is 148 bytes; GC/1.3 emits 152 bytes and scores 95.675674%. The
 * remaining difference is first-array address materialization; no inline
 * assembly or register binding is used. */
void fn_80126084(void)
{
    int i;
    Entry* entry;

    entry = lbl_80514AE0;
    for (i = 0; i < 20; i++, entry = (Entry*)((u8*)entry + 0x48C8)) {
        if (entry->state == 1)
            fn_8011F7E0(entry->object, 0);
    }
    entry = lbl_8056FA80;
    for (i = 0; i < 48; i++, entry = (Entry*)((u8*)entry + 0x1238)) {
        if (entry->state == 1)
            fn_8011F7E0(entry->object, 0);
    }
}
