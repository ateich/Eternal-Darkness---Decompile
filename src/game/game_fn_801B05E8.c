typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Entry {
    u8 pad000[0x144];
    int object;
    int handle;
    Vec3 position;
    float distance;
    int owner;
    int secondary;
    int timer;
    int first;
    int second;
    u8 active_a;
    u8 active_b;
    u8 pad172[2];
    u16 flags;
    u8 computed_volume;
    u8 volume;
    u8 kind;
    u8 wanted;
    u8 mode;
    u8 phase;
    u8 spatial;
    u8 count;
    u8 direct;
    u8 report;
    u8 active;
    u8 reason;
    u8 pad182[2];
} Entry;

extern Entry lbl_8060B5E0[4];
extern int lbl_8064D314;
extern int lbl_8064D5A8;
extern float lbl_80650EA8;
extern float lbl_80650EAC;
extern int fn_801AF180(int);
extern int fn_801B002C(int, u8, int, int, int);
extern void fn_801B0E68(int);
extern void fn_801B01F8(Entry*, int, int);
extern u8 fn_801ABF34(Vec3*, float, int, u8, u8);
extern int fn_801B0138(Entry*, int);

int fn_801B05E8(int owner, u8 volume, u8 wanted, u8 spatial, Vec3* position,
                u8 kind, int force_direct, int direct)
{
    int result = -1;

    if (owner < 0x2DB) {
        int i;
        Entry* entry;
        u8 type;
        int available;
        u8 effective;

        entry = lbl_8060B5E0;
        available = 1;
        type = fn_801AF180(owner);
        effective = force_direct == 1 ? 1 : type;

        for (i = 0; i < 4; i++, entry++) {
            if (entry->owner == owner) {
                if (direct == 1 &&
                    (entry->mode == 4 || entry->mode == 5 || entry->mode == 6)) {
                    fn_801B0E68(3);
                    result = entry->handle;
                    available = 0;
                } else if (entry->mode != 0 && entry->mode != 1 &&
                           entry->direct == effective) {
                    fn_801B0E68(4);
                    fn_801B01F8(entry, 15, 6);
                }
            }
        }

        if (available != 0) {
            entry = lbl_8060B5E0;
            for (i = 0; i < 4; i++, entry++) {
                if (entry->mode == 0) {
                    if (fn_801B002C(owner, wanted, spatial, 0,
                                    force_direct) == 0) {
                        break;
                    }

                    entry->owner = owner;
                    entry->flags = 0;
                    entry->volume = volume;
                    entry->kind = kind;
                    entry->distance = lbl_80650EAC;
                    if (position != 0) {
                        entry->position = *position;
                        entry->computed_volume = fn_801ABF34(position,
                            entry->distance, 0, volume, kind);
                    } else {
                        entry->position.z = lbl_80650EA8;
                        entry->position.y = lbl_80650EA8;
                        entry->position.x = lbl_80650EA8;
                        entry->computed_volume = volume;
                    }
                    entry->wanted = wanted;
                    entry->spatial = spatial;
                    entry->object = -1;
                    entry->count = 0;
                    result = lbl_8064D314;
                    entry->handle = lbl_8064D314;
                    entry->report = 0;
                    entry->reason = 0;
                    entry->active_a = 2;
                    entry->active_b = 2;
                    entry->secondary = -1;
                    entry->timer = 0;
                    entry->first = 0;
                    entry->second = 0;
                    lbl_8064D314++;
                    entry->active = 0;
                    entry->direct = type;

                    if (force_direct == 1 && entry->direct == 2) {
                        entry->direct = 1;
                        entry->active = 1;
                    }

                    if (direct == 1) {
                        entry->mode = 5;
                        entry->phase = 2;
                        fn_801B0138(entry, 1);
                    } else {
                        entry->first = lbl_8064D5A8;
                        entry->mode = 3;
                        entry->phase = 1;
                        fn_801B0138(entry, 0);
                    }
                    break;
                }
            }

            if (i == 4 && (unsigned)(owner - 0x1E5) > 1 &&
                (unsigned)(owner - 0x1E8) > 3 &&
                (unsigned)(owner - 0x16) > 1) {
                fn_801B0E68(5);
            }
        }
    }

    return result;
}
