typedef signed int s32;
typedef unsigned char u8;

typedef struct Descriptor {
    s32 words[5];
} Descriptor;

typedef struct Entry {
    s32 value;
    u8 type;
    u8 pad[3];
    u8 rest[0x1C];
} Entry;

extern const Descriptor lbl_802390B4;
extern Entry *lbl_8064C8D4;
extern void *lbl_80243F74[];
extern s32 fn_8006B620(s32 value);
extern void fn_8006BE84(Entry *entry, s32 value);
extern void fn_8006BE8C(Entry *entry);
extern void fn_8006DE98(void);
extern void fn_8006BEE4(Entry *entry, void (*callback)(void));
extern void fn_8006BEEC(Entry *entry, void *value);
extern void fn_8006BEF4(Entry *entry, Descriptor *descriptor);

void fn_8006B488(s32 first, s32 last, s32 *count, s32 *mask_a, s32 *mask_b)
{
    Descriptor descriptor;
    s32 i = first;
    Entry *entry;

    descriptor = lbl_802390B4;
    entry = &lbl_8064C8D4[*count];
    for (; i <= last; i++) {
        if (*count < 44) {
            descriptor.words[4] = fn_8006B620(i);
            fn_8006BE84(entry, i);
            fn_8006BE8C(entry);
            fn_8006BEE4(entry, fn_8006DE98);
            fn_8006BEEC(entry, lbl_80243F74[*count]);
            fn_8006BEF4(entry, &descriptor);

            if ((descriptor.words[4] & 1) != 0) {
                switch (entry->type) {
                case 2:
                    if (i >= 32) {
                        *mask_a |= 1 << (i - 32);
                    } else {
                        *mask_a |= 1 << i;
                    }
                    break;
                case 3:
                    if (i >= 32) {
                        *mask_b |= 1 << (i - 32);
                    } else {
                        *mask_b |= 1 << i;
                    }
                    break;
                }
            }
            entry++;
            (*count)++;
        }
    }
}
