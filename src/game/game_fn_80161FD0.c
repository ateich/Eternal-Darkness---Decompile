typedef unsigned int u32;

typedef struct Entry {
    char pad00[0x10];
    u32 index;
} Entry;

extern void* lbl_8023A7F8[];
extern Entry* fn_801670A8(void*, void*);

void fn_80161FD0(void* owner)
{
    int i;

    for (i = 0; i < 18; i++) {
        Entry* entry = fn_801670A8(owner, lbl_8023A7F8[i]);
        entry->index = (unsigned char)(i + 3);
    }
}
