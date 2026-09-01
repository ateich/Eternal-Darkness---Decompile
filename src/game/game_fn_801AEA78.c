typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Entry {
    u8 state;
    u8 type;
    u8 padding02[130];
} Entry;

extern Entry lbl_8060B430[];
extern void fn_801ADC08(void);
extern void fn_801ADBC0(void);
extern u32 fn_801ADAF8(u32);

u32 fn_801AEA78(u32 id)
{
    u32 result = 0;
    u32 index;
    Entry* entry;

    fn_801ADC08();
    index = fn_801ADAF8(id);
    if (index != -1) {
        entry = &lbl_8060B430[index];
        result = entry->type;
    }
    fn_801ADBC0();
    return result;
}
