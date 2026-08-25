float fn_80173B6C(register short* source, register float* destination)
{
    register float value;

    asm { psq_l value, 0(source), 1, 5 }
    *destination = value;
    return value;
}
