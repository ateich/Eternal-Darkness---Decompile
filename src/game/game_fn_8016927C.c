typedef struct Value {
    int type;
    int unused;
    double data;
} Value;

typedef struct State State;

extern char lbl_8024FCB8[];
extern int fn_801691AC(State*, Value*, int);
extern void fn_8016044C(State*, Value*, int, char*);

void fn_8016927C(State* state, Value* value, int index)
{
    if (!fn_801691AC(state, value, index)) {
        fn_8016044C(state, value - 2, 2, lbl_8024FCB8);
    }
}
