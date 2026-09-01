typedef struct State {
    unsigned char prefix[400];
    unsigned int interrupts;
    unsigned int interrupt_depth;
} State;

extern State lbl_8060B430;
extern unsigned int OSDisableInterrupts(void);

void fn_801ADC08(void)
{
    unsigned int depth;

    depth = lbl_8060B430.interrupt_depth++;
    if (depth == 0) {
        lbl_8060B430.interrupts = OSDisableInterrupts();
    }
}
