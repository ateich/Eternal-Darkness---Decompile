typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Entry {
    u8 pad000[0x144];
    u32 object;
    u8 pad148[0x14];
    int owner;
    u8 pad160[4];
    int timer;
    u8 pad168[0x11];
    u8 wanted;
    u8 mode;
    u8 pad17b;
    u8 limit;
    u8 pad17d[3];
    u8 direct;
} Entry;

extern int lbl_8064D5A8;
extern int fn_801B002C(int, int, int, int, int);
extern int fn_801AF37C(Entry*);

int fn_801B0138(Entry* entry, int alternate)
{
    int result = 0;

    if (entry->object != (u32)-1) {
        result = 1;
    } else if (fn_801B002C(entry->owner, entry->wanted, entry->limit, 1,
                           entry->direct) != 0) {
        entry->object = fn_801AF37C(entry);
        if (entry->object != (u32)-1) {
            result = 1;
            if (alternate == 1) {
                entry->mode = 6;
            } else {
                entry->mode = 2;
                entry->timer = lbl_8064D5A8;
            }
        }
    }
    return result;
}
