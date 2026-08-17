typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct Entry {
    int flags;
    int id;
    void* owner;
    Vec3 position;
    float radius;
} Entry;

extern Entry lbl_805ADE20[15];
extern int lbl_8064CFB8;

int fn_80137E60(void* owner, Vec3* position, float radius)
{
    Entry* entry;
    int i;

    entry = lbl_805ADE20;
    for (i = 0; i < 15; i++, entry++) {
        if (entry->flags == 0) {
            int id;
            id = lbl_8064CFB8;
            entry->flags |= 1;
            entry->id = id;
            entry->owner = owner;
            entry->position = *position;
            entry->radius = radius;
            lbl_8064CFB8 = id + 1;
            return entry->id;
        }
    }
    return -1;
}
