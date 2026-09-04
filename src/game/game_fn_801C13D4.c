typedef unsigned int u32;

typedef struct Link {
    struct Link* next;
    struct Link* prev;
    u32 key;
    u32 value;
} Link;

typedef struct Voice {
    unsigned char pad_000[0xF4];
    u32 value;
    Link* link;
    Link* current;
} Voice;

extern u32 lbl_8064D458;
extern Link* lbl_8064D45C;
extern Link* lbl_8064D460;

u32 fn_801C13D4(Voice* voice, u32 remember)
{
    u32 key;
    Link* link;
    Link* previous;
    Link* free;
    Link* allocated;

    do {
        key = lbl_8064D458;
        lbl_8064D458 = key + 1;
    } while (key == 0xFFFFFFFF);

    link = lbl_8064D45C;
    previous = 0;
    while (link != 0) {
        if (link->key > key) {
            break;
        }
        if (link->key == key) {
            do {
                key = lbl_8064D458;
                lbl_8064D458 = key + 1;
            } while (key == 0xFFFFFFFF);
        }
        previous = link;
        link = link->next;
    }

    free = lbl_8064D460;
    if ((allocated = free) == 0) {
        return 0xFFFFFFFF;
    }
    lbl_8064D460 = free->next;
    if (free->next != 0) {
        lbl_8064D460->prev = 0;
    }

    if (previous == 0) {
        lbl_8064D45C = allocated;
    } else {
        previous->next = allocated;
    }
    allocated->prev = previous;
    allocated->next = link;
    if (link != 0) {
        link->prev = allocated;
    }
    allocated->key = key;
    allocated->value = voice->value;
    voice->current = remember ? allocated : 0;
    voice->link = allocated;
    return remember ? key : voice->value;
}
