typedef unsigned char u8;
typedef unsigned short u16;

extern int fn_8006BE44(void);
extern u16 fn_800AE864(unsigned int, u16*);
extern int fn_800AE88C(unsigned int);
extern int fn_801AF824(void);
extern int fn_800AE380(u16, unsigned int, void*, u16, u16, u16, u8, u16);

void fn_800AE954(void)
{
    u16 state;

    if (fn_8006BE44() == 3) {
        fn_800AE864(3, &state);
        fn_800AE88C(0);
        if (state == 0 && fn_801AF824() == 0) {
            fn_800AE380(0xFFFF, 2, 0, 1, 320, 10000, 3, 0);
        }
    }
}
