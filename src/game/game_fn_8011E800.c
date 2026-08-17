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

void fn_8011E800(int value)
{
    lbl_80332428[0].state = value;
    lbl_80332428[1].state = value;
    lbl_80332428[2].state = value;
    lbl_80332428[3].state = value;
    lbl_80332428[4].state = value;
    lbl_80332428[5].state = value;
}
