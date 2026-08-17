typedef struct Entry {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int state;
    int owner;
    int field18;
    int flags;
} Entry;
extern Entry lbl_805B4170[20];

Entry* fn_80144628(int owner, int value, int flags)
{
    int i;
    Entry* entry = lbl_805B4170;
    for (i = 0; i < 20; i++, entry++) {
        if (entry->state == -2) {
            entry->owner = owner;
            entry->field0 = 0;
            entry->field4 = value;
            entry->field8 = 0;
            entry->state = 1;
            entry->field18 = flags;
            return entry;
        }
    }
    return 0;
}
