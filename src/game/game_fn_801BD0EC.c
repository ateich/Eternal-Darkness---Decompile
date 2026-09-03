typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Entry {
    void* value;
    u16 id;
    u16 padding;
} Entry;

extern Entry lbl_8064D424;
extern Entry lbl_80620D48[];
extern u16 lbl_8064D3F4;
extern Entry* lbl_8064D42C;
extern int fn_801BD07C(void*, void*);
extern void* fn_801CC370(void*, void*, u32, u32, int (*)(void*, void*));

void* fn_801BD0EC(u16 id)
{
    lbl_8064D424.id = id;
    if ((lbl_8064D42C = fn_801CC370(&lbl_8064D424, lbl_80620D48,
                                    lbl_8064D3F4, sizeof(Entry),
                                    fn_801BD07C)) != 0) {
        return lbl_8064D42C->value;
    }
    return 0;
}
