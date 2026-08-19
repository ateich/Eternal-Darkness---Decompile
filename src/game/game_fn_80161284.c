typedef struct Object {
    char _pad00[0x60];
    int allocation_size;
} Object;

typedef struct Entry {
    int field00;
    int field04;
    int field08;
    int field0C;
    int field10;
    int field14;
    int field18;
    int count;
    int field20;
    int field24;
    int field28;
    int field2C;
    int field30;
    int field34;
    int field38;
} Entry;

extern char lbl_8064BA80;
extern int fn_801611F8(Entry*);
extern void* fn_8016B5CC(Object*, int, unsigned int, char*, int);

void fn_80161284(Object* object, Entry* entry)
{
    if (entry->count > 0)
        object->allocation_size -= fn_801611F8(entry);

    fn_8016B5CC(object, entry->field18, 0, &lbl_8064BA80, 78);
    fn_8016B5CC(object, entry->field38, 0, &lbl_8064BA80, 79);
    fn_8016B5CC(object, entry->field08, 0, &lbl_8064BA80, 80);
    fn_8016B5CC(object, entry->field00, 0, &lbl_8064BA80, 81);
    fn_8016B5CC(object, entry->field10, 0, &lbl_8064BA80, 82);
    fn_8016B5CC(object, entry->field2C, 0, &lbl_8064BA80, 83);
    fn_8016B5CC(object, (int)entry, 0, &lbl_8064BA80, 84);
}
