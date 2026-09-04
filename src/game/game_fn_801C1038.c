typedef unsigned int u32;

typedef struct Link {
    struct Link* next;
    struct Link* prev;
    u32 key;
    u32 value;
} Link;

extern Link* lbl_8064D45C;

Link* fn_801C1038(u32 key)
{
    Link* link = lbl_8064D45C;

    while (link != 0) {
        if (link->key == key) {
            return link;
        }
        if (link->key > key) {
            break;
        }
        link = link->next;
    }
    return 0;
}
