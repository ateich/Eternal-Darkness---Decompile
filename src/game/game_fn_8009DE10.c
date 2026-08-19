typedef unsigned char u8;

typedef struct Work8009DE10 {
    u8 pad00[0xAC];
    void* field_AC;
} Work8009DE10;

typedef struct State8009DE10 {
    u8 pad00[0xC4];
    Work8009DE10* work;
} State8009DE10;

extern void *fn_8006ED3C();
extern void fn_801A5BA0(void*);

int fn_8009DE10(register State8009DE10* state)
{
    int index;
    Work8009DE10* work = state->work;
    fn_8006ED3C(state, 0x13, &index);
    fn_801A5BA0(work->field_AC);
    return 1;
}
