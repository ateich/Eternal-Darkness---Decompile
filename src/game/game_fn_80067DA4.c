typedef signed int s32;

extern void *fn_801E8494(void *owner);
extern void *fn_801E849C(void *entry);
extern s32 fn_801E84A4(void *entry);
extern void *fn_801E84AC(void *entry);
extern void fn_801E84B4(void *entry, void *value);

void fn_80067DA4(void **owner)
{
    void *entry;
    void *value;

    entry = fn_801E8494(owner);
    value = *owner;
    while (entry != 0) {
        if (fn_801E84A4(entry) == 17 && value == fn_801E84AC(entry)) {
            fn_801E84B4(entry, 0);
        }
        entry = fn_801E849C(entry);
    }
}
