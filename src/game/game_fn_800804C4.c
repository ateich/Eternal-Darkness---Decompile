typedef unsigned char u8;

typedef struct GlobalState {
    u8 pad[0x48F];
    u8 timer;
} GlobalState;

extern GlobalState lbl_8031CD84;
extern int fn_80080530(int, int);

void fn_800804C4(int mode)
{
    int i;
    int released;

    i = 0;
    released = 0;
    do {
        released += fn_80080530(i, mode);
        i++;
    } while (i < 7);
    lbl_8031CD84.timer = 0;
}
