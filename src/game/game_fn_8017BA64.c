typedef unsigned char u8;

extern u8 lbl_8064A580[];

extern void fn_8017B344(int index, int value);
extern void fn_8017AF78(void);

void fn_8017BA64(unsigned int index)
{
    void (*callback)(int);
    u8* state = lbl_8064A580;
    unsigned int saved_index = index;
    callback = *(void (**)(int))(state + 0x44);

    fn_8017B344(saved_index, 0);
    state[saved_index + 0x40] = 0;
    *(int*)(state + saved_index * 8 + 0x34) = 0;
    *(int*)(state + saved_index * 8 + 0x30) = 0;
    *(void (**)(int))(state + 0x44) = 0;
    if (callback != 0) {
        callback(saved_index);
    }
    fn_8017AF78();
}
