typedef struct Entry {
    unsigned int flags;
    int id;
    void* owner;
    float position[3];
    float radius;
} Entry;

extern Entry lbl_805ADE20[15];
extern int lbl_8064CFB8;
extern void fn_80137DD4(Entry* entry);

void fn_80137E04(void)
{
    int i;
    Entry* entry;

    entry = lbl_805ADE20;
    for (i = 0; i < 15; i++, entry++) {
        fn_80137DD4(entry);
    }
    lbl_8064CFB8 = 0;
}
