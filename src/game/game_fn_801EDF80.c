typedef signed short s16;
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;

/* Slot table owned by the animation sampler. */
typedef struct Slot Slot;

extern int lbl_80265D80[];
extern int lbl_8064C378;
extern u8 lbl_8064D5F8;
extern int lbl_8064D634;
extern int lbl_8064D638;
extern u8 lbl_8064D674[4];
extern int lbl_8064D6E8;
extern int lbl_8064D6F0;
extern u8 lbl_80639260[];

extern void fn_801ECD74(u32*);
extern void fn_801ED118(void);
extern u16 fn_801F6034(int, Slot*);

/*
 * Central controller-state dispatcher.  The entry filter and first-pass
 * channel synchronization are recovered here.  Retail continues through the
 * per-channel caches and command emitters; those bodies remain incomplete.
 */
int fn_801EDF80(s16* values, int total, int count, int iteration_total,
                int* parameter, int mode, int channel, Slot* context, int flags,
                void* state)
{
    u32 attributes;
    int first_pass;
    int command;
    int repeat;
    int selector;
    int accepted;
    int index;

    attributes = values != 0 ? *(u32*)((char*)values + 0x18) : 0x80000000;
    if (flags & 0x8000) {
        attributes |= 0x80000000;
    }

    if (total == 0) {
        if (attributes & 0x80000000) {
            command = 2;
            repeat = 1;
            selector = 0xFF;
        } else {
            command = 10;
            repeat = 5;
            selector = 4;
        }
        first_pass = 1;
    } else {
        command = 0;
        repeat = 0;
        selector = 0;
        first_pass = 0;
    }
    if (lbl_8064D638 == 0) {
        selector = 0xFF;
    }

    if (channel == 10 && (flags & 0x800) == 0) {
        accepted = 1;
        if (values != 0) {
            u32 color = *(u32*)((char*)values + 0x1C);
            fn_801ECD74(&color);
        } else {
            u32 color = *(u32*)((char*)state + 0x58);
            fn_801ECD74(&color);
        }

        for (index = 0; index < 4; index++) {
            int slot = lbl_80265D80[index];
            int candidate;
            u32 bit;

            if (slot == 7) {
                continue;
            }
            if (values != 0) {
                candidate = values[slot];
                if (slot == 1) {
                    switch (lbl_8064D5F8) {
                    case 0:
                        candidate = values[1];
                        break;
                    case 1:
                        candidate = values[6];
                        break;
                    case 2:
                        candidate = values[8];
                        break;
                    }
                }
            } else {
                candidate = *(s16*)((char*)state + 0x5C + slot * 2);
            }
            if (candidate == -1) {
                continue;
            }

            bit = 1U << slot;
            if (((u32)flags & bit) != 0 &&
                (((u32)lbl_8064C378 & bit) != 0 || lbl_8064D6E8 != 0)) {
                accepted = 0;
                break;
            }
        }

        if (!accepted) {
            if ((lbl_8064D674[0] == 0xFF && lbl_8064D674[1] == 0xFF &&
                 lbl_8064D674[2] == 0xFF && lbl_8064D674[3] == 0xFF) ||
                (attributes & 0x80000000) != 0) {
                return 0;
            }
            command = 10;
            repeat = 5;
            selector = 4;
        }
    }

    if (channel == 2 && lbl_8064D6F0 == 0) {
        return 0;
    }

    if (first_pass && lbl_8064D634 != channel) {
        fn_801ED118();
        lbl_8064D634 = channel;
    }

    /*
     * Retail keeps a signed sample and the corresponding attribute bit for
     * each channel.  Channel one additionally invalidates its sample whenever
     * any member of the remappable three-value group changes.
     */
    if (channel != 10) {
        s16* cached_values = (s16*)(lbl_80639260 + 0x21D8);
        u32* cached_attributes = (u32*)(lbl_80639260 + 0x21F0);
        int candidate;
        u32 bit = 1U << channel;

        if (values != 0) {
            candidate = values[channel];
            if (channel == 1) {
                int* group = (int*)(lbl_80639260 + 0x21CC);

                switch (lbl_8064D5F8) {
                case 0:
                    candidate = values[1];
                    break;
                case 1:
                    candidate = values[6];
                    break;
                case 2:
                    candidate = values[8];
                    break;
                }
                if (group[0] != values[1] || group[1] != values[6] ||
                    group[2] != values[8]) {
                    group[0] = values[1];
                    group[1] = values[6];
                    group[2] = values[8];
                    cached_values[channel] = -1;
                }
            }
        } else {
            candidate = *(s16*)((char*)state + 0x5C + channel * 2);
        }

        if ((attributes & bit) != (*cached_attributes & bit) ||
            cached_values[channel] != candidate) {
            if ((attributes & bit) != 0) {
                candidate = (s16)fn_801F6034(values[channel], context);
            }
            if ((s16)candidate != cached_values[channel]) {
                cached_values[channel] = (s16)candidate;
                /* Retail's per-channel change handler follows this store. */
            }
        }
    }

    /* The per-channel change handlers and command dispatch remain incomplete. */
    (void)count;
    (void)iteration_total;
    (void)parameter;
    (void)mode;
    (void)command;
    (void)repeat;
    (void)selector;
    return 0;
}
