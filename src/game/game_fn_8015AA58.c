typedef unsigned int u32;

typedef struct InitState {
    u32 words[71];
} InitState;

extern InitState lbl_805E2640;
extern void fn_8015AA28(int);

void fn_8015AA58(InitState* state)
{
    fn_8015AA28(1);
    lbl_805E2640 = *state;
}
