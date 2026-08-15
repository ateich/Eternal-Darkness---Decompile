typedef struct Entry {
    unsigned char pad[52];
    unsigned char flags;
    unsigned char tail[3];
} Entry;

typedef struct ListNode ListNode;

extern Entry *lbl_8064CA74;
extern ListNode *fn_800BD6F0(void);
extern void fn_800BD628(ListNode *);

void fn_800BD828(void)
{
    ListNode *node;
    int i;

    for (i = 0; i < 500; i++) {
        lbl_8064CA74[i].flags &= ~1;
    }
    while ((node = fn_800BD6F0()) != 0) {
        fn_800BD628(node);
    }
}
