typedef unsigned short u16;

typedef struct GroupEntry {
    u16 id;
    u16 state;
    unsigned char padding[0x1C];
} GroupEntry;

typedef struct RegistryEntry {
    GroupEntry* entries;
    void* value;
    u16 count;
    u16 padding;
} RegistryEntry;

extern RegistryEntry lbl_8061C748[];
extern u16 lbl_8064D3F0;
extern void fn_801CE2B8(void);
extern void fn_801CE280(void);

int fn_801BC0D4(GroupEntry* entries, void* value)
{
    unsigned char* base = (unsigned char*)lbl_8061C748;
    u16 count;
    u16 inner;
    int registry_count = lbl_8064D3F0;
    int index = 0;
    u16 i;

    while (index < registry_count && ((RegistryEntry*)base)[index].entries != entries) {
        index++;
    }
    if (index == registry_count) {
        if ((unsigned)registry_count < 0x80) {
            count = 0;
            while (entries[count].id != 0xFFFF) {
                count++;
            }

            fn_801CE2B8();
            for (i = 0; i < count; i++) {
                RegistryEntry* current = (RegistryEntry*)base;
                int outer = 0;
                while (outer < lbl_8064D3F0) {
                    inner = 0;
                    {
                    GroupEntry* candidate = current->entries;
                    while ((u16)inner < current->count) {
                        if (entries[i].id == candidate->id) {
                            goto found;
                        }
                        candidate++;
                        inner++;
                    }
                    }
                    current++;
                    outer++;
                }
found:
                if (outer != lbl_8064D3F0) {
                    entries[i].state = 0xFFFF;
                } else {
                    entries[i].state = 0;
                }
            }

            {
                RegistryEntry* added = &((RegistryEntry*)base)[lbl_8064D3F0];
                added->entries = entries;
                added->count = count;
                added->value = value;
            }
            lbl_8064D3F0++;
            fn_801CE280();
            return 1;
        }
        return 0;
    }
    return 1;
}
