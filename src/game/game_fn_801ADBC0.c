typedef struct State {
    unsigned char prefix[400];
    unsigned int interrupts;
    unsigned int interrupt_depth;
} State;

extern State lbl_8060B430;
extern void OSRestoreInterrupts(unsigned int);

void fn_801ADBC0(void)
{
    if (lbl_8060B430.interrupt_depth != 0) {
        lbl_8060B430.interrupt_depth--;
        if (lbl_8060B430.interrupt_depth == 0) {
            OSRestoreInterrupts(lbl_8060B430.interrupts);
        }
    }
}
