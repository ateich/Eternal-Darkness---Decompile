typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Entry Entry;
struct Entry {
    u8 state;
    u8 padding01[7];
    Entry* first;
    Entry* second;
    u8 padding10[90];
    u8 phase;
    u8 padding6B[25];
};

extern Entry lbl_8060B430[];
extern void fn_801ADC08(void);
extern void fn_801ADBC0(void);
extern u32 fn_801ADAF8(u32);
extern int fn_801AE5DC(Entry*);

u32 fn_801AEB74(u32 id)
{
    u32 index;
    u32 result = 0;
    Entry* entry;

    fn_801ADC08();
    index = fn_801ADAF8(id);
    fn_801ADBC0();
    if (index != -1) {
        entry = &lbl_8060B430[index];
        if ((entry->first == 0 || entry->first->phase == 3) &&
            (entry->second == 0 || entry->second->phase == 3)) {
            if (fn_801AE5DC(entry)) {
                result = 1;
                if (entry->first != 0 && !fn_801AE5DC(entry->first)) {
                    entry->first->second = 0;
                    entry->first = 0;
                    result = 0;
                }
                if (entry->second != 0 && !fn_801AE5DC(entry->second)) {
                    entry->second->first = 0;
                    entry->second = 0;
                    result = 0;
                }
            } else {
                if (entry->first != 0) {
                    entry->first->second = 0;
                    entry->first = 0;
                }
                if (entry->second != 0) {
                    entry->second->first = 0;
                    entry->second = 0;
                }
            }
        }
    }
    return result;
}
