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

void fn_8011E7E8(void* value, int index)
{
    lbl_80332428[index].state = (int)value;
}
