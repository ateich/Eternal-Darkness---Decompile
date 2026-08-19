typedef struct Value {
    int type;
    int unused;
    double data;
} Value;

typedef struct State {
    Value* top;
    char pad04[0x44];
    struct CallbackSet* callbacks;
} State;

typedef struct CallbackSet {
    void* values[16];
} CallbackSet;

extern void* lbl_8023A8B0[];
extern int fn_80167D2C(Value*);
extern void fn_8016A8F8(State*, void*);
extern void fn_80160AA0(State*, void*, int, int);

int fn_801691AC(State* state, Value* value, int index)
{
    void* callback = state->callbacks[fn_80167D2C(value - 2)].values[index];

    state->top = value;
    if (callback == 0) {
        callback = state->callbacks[fn_80167D2C(value - 1)].values[index];
        if (callback == 0) {
            callback = state->callbacks[0].values[index];
            if (callback == 0) {
                return 0;
            }
        }
    }

    fn_8016A8F8(state, lbl_8023A8B0[index]);
    fn_80160AA0(state, callback, 3, 1);
    return 1;
}
