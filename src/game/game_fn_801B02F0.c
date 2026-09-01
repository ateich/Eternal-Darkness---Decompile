typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Entry {
    u8 pad000[0x144];
    u32 object;
    int secondary;
    float position[3];
    float distance;
    int owner;
    u8 pad160[0x12];
    s8 active_a;
    s8 active_b;
    u16 flags;
    u8 computed_volume;
    u8 volume;
    s8 kind;
    u8 wanted;
    u8 mode;
    u8 phase;
    u8 pad17c;
    u8 report;
    u8 spatial;
    u8 volume_count;
    u8 pad180;
    u8 reason;
    u8 pad182[2];
} Entry;

extern Entry lbl_8060B5E0[4];
extern Entry* lbl_8064D310;
extern float lbl_80650EA8;
extern u32 fn_801AE284(u32);
extern void fn_801AE1D0(u32, int);
extern int fn_801B0138(Entry*, int);
extern u8 fn_801AEAE0(u32);
extern int fn_801AEB74(u32);
extern void fn_801B0E68(int);
extern void fn_801B01F8(Entry*, u8, u8);
extern void fn_801AFA74(float*, int*, int*);
extern u8 fn_801ABF34(float*, float, int, u8, s8);
extern void fn_801AE91C(u32, u8, int, int);

void fn_801B02F0(void)
{
    int i;
    Entry* entry = lbl_8060B5E0;

    for (i = 0; i < 4; i++, entry++) {
        int update = 0;
        switch (entry->mode) {
        case 0:
            break;
        case 1:
            if (fn_801AE284(entry->object) == 0) {
                if (entry->active_a == 0 && entry->active_b == 0) {
                    entry->mode = 0;
                    entry->object = (u32)-1;
                    if (entry == lbl_8064D310) {
                        lbl_8064D310 = 0;
                    }
                }
            } else if (entry->volume_count > 1 && entry->secondary != -1) {
                entry->volume = (u8)((entry->volume * (entry->volume_count - 1)) /
                                     entry->volume_count);
                entry->volume_count--;
                update = 1;
            } else {
                fn_801AE1D0(entry->object, 0);
            }
            break;
        case 2:
            if (fn_801AE284(entry->object) == 0) {
                entry->mode = 0;
                entry->object = (u32)-1;
                entry->reason = 1;
                if (entry == lbl_8064D310) {
                    lbl_8064D310 = 0;
                }
            } else {
                update = 1;
            }
            break;
        case 3:
            fn_801B0138(entry, 0);
            break;
        case 5:
            if (fn_801B0138(entry, 1) == 0) {
                break;
            }
        case 6:
            entry->phase = fn_801AEAE0(entry->object);
            if (entry->phase != 3) {
                break;
            }
            entry->mode = 4;
        case 4:
            if (entry->report != 0) {
                if (fn_801AEAE0(entry->object) != 3) {
                    fn_801B0E68(2);
                }
                if (fn_801AEB74(entry->object) != 0) {
                    entry->phase = 4;
                    entry->mode = 2;
                    update = 1;
                } else {
                    fn_801B01F8(entry, 0, 5);
                }
            }
            break;
        }

        if (update != 0) {
            int first = -1;
            int second = -1;
            if (entry->spatial == 1 && entry->kind != 5 &&
                (entry->flags & 2) == 0 &&
                (lbl_80650EA8 != entry->position[0] ||
                 lbl_80650EA8 != entry->position[1] ||
                 lbl_80650EA8 != entry->position[2])) {
                fn_801AFA74(entry->position, &first, &second);
                entry->computed_volume = fn_801ABF34(entry->position,
                    entry->distance, 0, entry->volume, entry->kind);
            } else {
                entry->computed_volume = entry->volume;
            }
            fn_801AE91C(entry->object, entry->computed_volume, first, second);
        }
    }
}
