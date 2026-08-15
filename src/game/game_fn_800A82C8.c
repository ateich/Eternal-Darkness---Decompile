typedef struct InnerState {
    unsigned char pad0[0x24];
    void* value;
} InnerState;

typedef struct OuterState {
    unsigned char pad0[0x8C];
    InnerState* inner;
} OuterState;

extern void* fn_80201ADC(void);
extern OuterState* fn_80201B8C();

void* fn_800A82C8(void)
{
    void* result = 0;

    if (fn_80201ADC() != 0) {
        OuterState* outer = fn_80201B8C();
        if (outer != 0 && outer->inner != 0) {
            result = outer->inner->value;
        }
    }
    return result;
}
