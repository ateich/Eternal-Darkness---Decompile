typedef signed char s8;
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Entry {
    u8 pad000[0x144];
    u32 object;
    u8 pad148[0x2A];
    s8 active_a;
    s8 active_b;
    u8 pad174[6];
    u8 mode;
    u8 pad17b[4];
    u8 volume;
    u8 pad180;
    u8 reason;
} Entry;

extern Entry* lbl_8064D310;
extern u32 fn_801AE284(u32);
extern void fn_801AE1D0(u32, int);

void fn_801B01F8(Entry* entry, u8 volume, u8 reason)
{
    if (entry != 0) {
        entry->reason = reason;
        if (entry->mode != 0 && entry->mode != 1) {
            if (volume != 0) {
                entry->volume = volume;
                entry->mode = 1;
            } else if (fn_801AE284(entry->object) != 0) {
                fn_801AE1D0(entry->object, 0);
                entry->mode = 1;
            } else if (entry->active_a != 0 || entry->active_b != 0) {
                entry->mode = 1;
            } else {
                entry->mode = 0;
                entry->object = (u32)-1;
                if (entry == lbl_8064D310) {
                    lbl_8064D310 = 0;
                }
            }
        } else {
            entry->volume = volume < entry->volume ? volume : entry->volume;
        }
    }
}
