typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Entry {
    u8 active;
    u8 padding01[7];
    struct Entry* child1;
    struct Entry* child2;
    u8 remainder[116];
} Entry;

extern Entry lbl_8060B430[];
extern void fn_801ADC08(void);
extern void fn_801ADBC0(void);
extern u32 fn_801ADAF8(u32);
extern void fn_801AE140(Entry*, int);

void fn_801AE1D0(u32 id, int stop)
{
    u32 index;

    if (id != 0xFFFFFFFF) {
        fn_801ADC08();
        index = fn_801ADAF8(id);
        if (index != 0xFFFFFFFF) {
            fn_801AE140(&lbl_8060B430[index], stop);
            if (lbl_8060B430[index].child1 != 0) {
                fn_801AE140(lbl_8060B430[index].child1, stop);
            }
            if (lbl_8060B430[index].child2 != 0) {
                fn_801AE140(lbl_8060B430[index].child2, stop);
            }
        }
        fn_801ADBC0();
    }
}
