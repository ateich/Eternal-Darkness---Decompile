typedef signed short s16;

extern void fn_801252D8(int);

void fn_801270DC(register float* output, register s16* input)
{
    fn_801252D8(4);
    asm {
        psq_l f0, 0(input), 0, 2
        psq_lu f1, 4(input), 1, 2
        psq_st f0, 0(output), 0, 0
        psq_stu f1, 8(output), 1, 0
    }
}
