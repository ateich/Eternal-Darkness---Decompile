typedef signed char s8;

typedef struct InnerState {
    unsigned char pad[0x42];
    s8 value;
} InnerState;

typedef struct OuterState {
    unsigned char pad[0x58];
    InnerState* inner;
} OuterState;

extern void* lbl_8064C98C;
extern void* fn_80201814();
extern OuterState* fn_80201B8C();

int fn_800ACFE8(void)
{
    int result = -1;
    void* object = fn_80201814(lbl_8064C98C);
    if (object != 0) {
        result = fn_80201B8C(object)->inner->value;
    }
    return result;
}
