typedef struct State {
    int duration;
    unsigned char rest[40];
} State;

extern State lbl_805B701C;

int fn_8015C9F0(void)
{
    return lbl_805B701C.duration;
}
