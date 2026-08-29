typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_80225F4C(int, void*, int);
extern int fn_8017FFB8(void);
extern int fn_8017FF98(void);
extern int fn_8017FFB0(void);
extern void fn_8022A75C(int, int, int);
extern int* fn_801EF2B0(void);
extern void fn_8022B7CC(u16, int, int);
extern void fn_801EDEC4(u16, int, int, int);
extern void fn_80226AB4(int, int, int);
extern void fn_8019F1B0(void);
extern void fn_8019F1B4(u16);
extern void fn_8019F1C0(u16);
extern void fn_8019F1CC(u16);

void fn_8019F00C(void* a, void* b, void* c, void* d, int count)
{
    u16 outer;
    u16 previous;

    fn_80225F4C(23, d, 48);
    fn_80225F4C(9, a, (u8)fn_8017FFB8());
    fn_80225F4C(11, c, (u8)fn_8017FF98());
    fn_80225F4C(13, b, (u8)fn_8017FFB0());
    fn_8022A75C(1, 3, 0);

    previous = (u16)(unsigned long)a;
    for (outer = 0; outer < count; outer++) {
        int* entries = fn_801EF2B0();
        u16 index;
        u16 first;
        u16 end;

        fn_8022B7CC(outer, 30, 1);
        for (index = 0; index < 16; index++) {
            if (entries[index] == 0) {
                fn_801EDEC4(index, 1, 4, 30);
                break;
            }
        }
        for (index = 0; index < 16; index++) {
            if (entries[index] == 5) {
                fn_801EDEC4(index, 1, 4, 30);
                break;
            }
        }
        fn_80226AB4(128, 5, 4);
        first = previous * 4;
        end = first + 4;
        for (; first < end; first++) {
            fn_8019F1CC(first);
            fn_8019F1C0(first);
            fn_8019F1B4(first);
        }
        fn_8019F1B0();
        previous = outer;
    }
    fn_8022A75C(1, 3, 1);
}
