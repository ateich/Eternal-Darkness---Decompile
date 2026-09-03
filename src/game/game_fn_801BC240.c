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

int fn_801BC240(GroupEntry* entries)
{
    unsigned char* base = (unsigned char*)lbl_8061C748;
    int index = 0;
    int i;
    int result = 0;

    {
    RegistryEntry* current = (RegistryEntry*)base;
    while (index < lbl_8064D3F0 && current->entries != entries) {
        current++;
        index++;
    }
    }
    if (index != lbl_8064D3F0) {

    fn_801CE2B8();
    {
        GroupEntry* entry = entries;
        while (entry->id != 0xFFFF) {
            if (entry->state != 0xFFFF && entry->state != 0) {
                fn_801CE280();
                return 0;
            }
            entry++;
        }
    }

    {
        GroupEntry* entry = entries;
        while (entry->id != 0xFFFF) {
            if (entry->state != 0xFFFF) {
                RegistryEntry* other = (RegistryEntry*)base;
                int outer = 0;
                while (outer < lbl_8064D3F0) {
                    if (other->entries != entries) {
                        GroupEntry* candidate = other->entries;
                        int inner = 0;
                        while (inner < other->count) {
                            if (entry->id == candidate->id && candidate->state == 0xFFFF) {
                                other->entries[inner].state = 0;
                                break;
                            }
                            candidate++;
                            inner++;
                        }
                        if (inner != other->count) {
                            break;
                        }
                    }
                    other++;
                    outer++;
                }
            }
            entry++;
        }
    }

    {
        GroupEntry* entry = entries;
        while (entry->id != 0xFFFF) {
            entry->state = 0;
            entry++;
        }
    }

    for (i = index + 1; i < lbl_8064D3F0; i++) {
        lbl_8061C748[i - 1] = lbl_8061C748[i];
    }
    lbl_8064D3F0--;
    fn_801CE280();
    result = 1;
    }
    return result;
}
