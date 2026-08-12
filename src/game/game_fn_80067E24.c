typedef signed int s32;

typedef struct RuntimeObject {
    unsigned char data[0xC4];
    void *attachment;
} RuntimeObject;

extern void *fn_8014C7B0(void *attachment);
extern void *fn_801E8494(void *owner);
extern void *fn_801E849C(void *entry);
extern s32 fn_801E84A4(void *entry);
extern void *fn_801E84AC(void *entry);
extern void fn_801E84B4(void *entry, void *value);

void fn_80067E24(RuntimeObject **owner)
{
    void *value;
    void *entry;

    entry = fn_801E8494(owner);
    if ((*owner)->attachment != 0) {
        value = fn_8014C7B0((*owner)->attachment);
        while (entry != 0) {
            if (fn_801E84A4(entry) == 19 && value == fn_801E84AC(entry)) {
                fn_801E84B4(entry, 0);
            }
            entry = fn_801E849C(entry);
        }
    }
}
