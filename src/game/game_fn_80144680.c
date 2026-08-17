typedef struct Entry { char pad[0x1C]; unsigned int flags; } Entry;
extern Entry* lbl_8064D074;

void fn_80144680(Entry* entry)
{
    if (entry != 0) {
        entry->flags |= 1;
        if (lbl_8064D074 == entry)
            lbl_8064D074 = 0;
    }
}
