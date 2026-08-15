typedef unsigned char u8;
typedef unsigned short u16;

extern int lbl_8064D18C;
extern int fn_8006B96C(int, int);
extern int fn_800AE380(u16, unsigned int, void*, u16, u16, u16, u8, u16);
extern u16 fn_800AE864(unsigned int, u16*);

void fn_800AF11C(void* object)
{
    u8* runtime = *(u8**)((u8*)object + 0xC4);
    u16 state;

    if (runtime[6] == 5 && fn_8006B96C(lbl_8064D18C, 3) == -1) {
        fn_800AE380(0xFFFF, 4, 0, 5, 320, 18000, 3, 0);
        runtime[6] = 0;
        fn_800AE864(4, &state);
    }
    runtime[6]++;
    if (runtime[6] > 5) {
        runtime[6] = 0;
    }
}
