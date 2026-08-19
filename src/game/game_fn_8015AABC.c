typedef unsigned int u32;

typedef struct InitState {
    u32 words[71];
} InitState;

extern InitState lbl_805E2640;
extern int fn_8015AA20(void);

InitState* fn_8015AABC(void)
{
    InitState* result = 0;

    if (fn_8015AA20() != 0) {
        result = &lbl_805E2640;
    }

    return result;
}
