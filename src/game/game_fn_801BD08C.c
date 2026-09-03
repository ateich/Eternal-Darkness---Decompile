typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Entry {
    void* value;
    u16 id;
    u16 padding;
} Entry;

extern Entry lbl_8064D418;
extern Entry lbl_8061CD48[];
extern u16 lbl_8064D3F2;
extern Entry* lbl_8064D420;
extern int fn_801BD07C(void*, void*);
extern void* fn_801CC370(void*, void*, u32, u32, int (*)(void*, void*));

void* fn_801BD08C(u16 id)
{
    lbl_8064D418.id = id;
    if ((lbl_8064D420 = fn_801CC370(&lbl_8064D418, lbl_8061CD48,
                                    lbl_8064D3F2, sizeof(Entry),
                                    fn_801BD07C)) != 0) {
        return lbl_8064D420->value;
    }
    return 0;
}
