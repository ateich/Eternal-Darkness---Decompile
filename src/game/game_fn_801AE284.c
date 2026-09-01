typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Entry {
    u8 active;
    u8 remainder[131];
} Entry;

extern Entry lbl_8060B430[];
extern void fn_801ADC08(void);
extern void fn_801ADBC0(void);
extern u32 fn_801ADAF8(u32);

u32 fn_801AE284(u32 id)
{
    u32 result = 0;
    u32 index;

    fn_801ADC08();
    index = fn_801ADAF8(id);
    if (index != 0xFFFFFFFF) {
        result = lbl_8060B430[index].active != 0;
    }
    fn_801ADBC0();
    return result;
}
