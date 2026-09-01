typedef struct State801B19BC {
    unsigned char pad[0x18];
    unsigned char data;
} State801B19BC;

extern State801B19BC* lbl_8064D348;

void* fn_801B19BC(void)
{
    if (lbl_8064D348 != 0) {
        return &lbl_8064D348->data;
    }
    return 0;
}
