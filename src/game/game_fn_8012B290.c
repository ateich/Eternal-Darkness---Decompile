typedef unsigned char u8;
typedef unsigned short u16;

typedef void (*Callback8012B290)(void*, void*);

extern void fn_80128C50(void*);

void fn_8012B290(void* owner, u8* state)
{
    void* callback;
    void* candidate;
    void* argument;
    int next_state;

    next_state = 1;
    callback = 0;
    argument = 0;
    if ((*(u16*)(state + 0xFC) & 4) != 0) {
        candidate = *(void**)(state + 0xA8);
        if (candidate != 0) {
            argument = *(void**)(state + 0xAC);
            callback = candidate;
            *(void**)(state + 0xA8) = 0;
        }
        next_state = 8;
    }
    *(u16*)(state + 0xFC) = next_state;
    if (callback != 0) {
        ((Callback8012B290)callback)(owner, argument);
        if ((*(u16*)(state + 0xFC) & 9) != 0) {
            fn_80128C50(state);
        }
    } else {
        fn_80128C50(state);
    }
}
