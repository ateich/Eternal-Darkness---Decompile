typedef struct StreamState {
    unsigned char pad[0x4C];
    void* manager;
} StreamState;

extern StreamState lbl_805BB1E0;

void* fn_8015E4A4(void)
{
    return lbl_805BB1E0.manager;
}
