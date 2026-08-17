typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Entry {
    void* object;
    u32 id;
    u32 field_8;
    void* resource;
    void* context;
    Vec3 position;
    u8 flags;
    char pad_21[7];
} Entry;

typedef struct Manager {
    char pad_0[5];
    u8 count;
    u8 range;
    char pad_7[9];
    Entry* entries;
} Manager;

extern void fn_8011F114(Vec3*, void*);
extern void fn_8012B7A0(void*, float);
extern float lbl_80650248;

/* Retail additionally searches the live-object iterator for the nearest
 * eligible object when an entry has no owner, installs its resource/context,
 * and applies the entry flag modes.  The owned-entry maintenance pass is
 * recovered here while that selection path remains under reconstruction. */
void fn_80133510(Manager* manager)
{
    int offset;
    int i;

    if (manager == 0) {
        return;
    }

    offset = 0;
    i = 0;
    while (i < manager->count) {
        Entry entry = *(Entry*)((char*)manager->entries + offset);

        if (entry.object == 0) {
            /* Nearest eligible live-object selection remains to be typed. */
        }
        offset += 0x28;
        i++;
    }

    offset = 0;
    i = 0;
    while (i < manager->count) {
        Entry* entry = (Entry*)((char*)manager->entries + offset);
        if (entry->object != 0) {
            fn_8011F114(&entry->position, entry->object);
            fn_8012B7A0(entry->object, lbl_80650248);
        }
        offset += 0x28;
        i++;
    }
}
