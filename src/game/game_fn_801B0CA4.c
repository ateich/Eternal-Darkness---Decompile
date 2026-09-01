typedef unsigned char u8;

typedef struct Entry {
    u8 pad000[0x16C];
    int stamp;
    u8 pad170[0xB];
    u8 mode;
    u8 pad17C;
    u8 active;
    u8 pad17E[6];
} Entry;

extern int lbl_8064D5A8;
extern Entry* fn_801B0A6C(int);
extern Entry* fn_801AF760(int);
extern void fn_801B0E68(int);

void fn_801B0CA4(int object, int owner)
{
    Entry* entry;

    if (object == -1) {
        entry = fn_801B0A6C(owner);
    } else {
        entry = fn_801AF760(object);
    }
    if (entry != 0) {
        if (entry->mode == 2) {
            entry->active = 1;
        } else if (entry->mode == 3) {
            entry->active = 1;
        } else if (entry->mode == 4) {
            entry->active = 1;
        }
        entry->stamp = lbl_8064D5A8;
    } else {
        fn_801B0E68(6);
    }
}
