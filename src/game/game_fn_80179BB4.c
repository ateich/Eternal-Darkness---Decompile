void fn_80179BB4(register float* source, register short* destination)
{
    asm {
        lfs f1, 0(source)
        psq_st f1, 0(destination), 1, 5
    }
}
