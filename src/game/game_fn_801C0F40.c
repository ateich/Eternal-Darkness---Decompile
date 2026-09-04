typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Link {
    struct Link* next;
    struct Link* prev;
    u8 pad_008[8];
} Link;

extern Link lbl_80626DA0[];
extern Link* lbl_8064D458;
extern Link* lbl_8064D45C;
extern Link* lbl_8064D460;

void fn_801C0F40(void)
{
    u32 i;
    Link* link;
    Link* previous;

    link = lbl_80626DA0;
    lbl_8064D460 = link;
    i = 0;
    lbl_8064D458 = 0;
    previous = 0;
    lbl_8064D45C = 0;

    for (; i < 128; i++) {
        link->prev = previous;
        if (previous != 0) {
            previous->next = link;
        }
        previous = link;
        link++;
    }
    previous->next = 0;
}
