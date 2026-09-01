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

u32 fn_801AEAE0(u32 id)
{
    u32 result = 0;
    u32 index;
    Entry* entry;

    fn_801ADC08();
    index = fn_801ADAF8(id);
    if (index != -1) {
        entry = &lbl_8060B430[index];
        result = entry->phase;
        if (result == 3) {
            if (entry->first != 0) {
                result = entry->first->phase;
            } else if (entry->second != 0) {
                result = entry->second->phase;
            }
        }
    }
    fn_801ADBC0();
    return result;
}
