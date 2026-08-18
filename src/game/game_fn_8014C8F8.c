typedef unsigned char u8;
typedef unsigned short u16;

typedef struct State {
    void* object;
    u8 pad04[4];
    int limit;
    int step;
    u8 pad10[0x12];
    u16 status;
    u16 threshold;
    short count;
    u8 pad28[0x1C];
    int current;
} State;

extern State* fn_801FD6F4(void*);
extern void fn_801FDF74(void*, int);
extern int fn_801FE05C(void*);

int fn_8014C8F8(void* object)
{
    State* state = fn_801FD6F4(object);
    int limit = state->limit;
    int step = state->step;

    if (state != 0) {
        if (state->count <= state->threshold) {
            int value = state->current + step;
            if (limit < value)
                value = limit;
            fn_801FDF74(object, value);
        } else if (fn_801FE05C(object)) {
            state->status = 2;
        }
    }
    return 1;
}
