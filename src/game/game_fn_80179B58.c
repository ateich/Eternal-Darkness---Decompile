float fn_80179B58(register short* source, register float* destination)
{
    register float value;

    asm { psq_l value, 0(source), 1, 5 }
    *destination = value;
    return value;
}
