typedef struct Entry {
    int value;
    void* object;
    int resource;
    void* callback;
    int state;
    int index;
    unsigned short flags;
    unsigned short pad;
} Entry;

extern Entry lbl_80332428[];
extern Entry lbl_803324D0;

extern void* memset(void*, int, unsigned long);
extern void fn_8011DD8C(int, int);

void fn_8011E26C(int release)
{
    int index = lbl_803324D0.index;

    memset(&lbl_803324D0, 0, sizeof(Entry));
    lbl_803324D0.resource = -1;
    lbl_803324D0.index = -1;
    lbl_803324D0.object = (void*)-1;

    if (index != -1 && release != 0 && lbl_80332428[index].resource != -1) {
        fn_8011DD8C(index, 0);
    }
}
