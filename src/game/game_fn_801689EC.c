int fn_801689EC(void)
{
    union {
        int word;
        signed char byte;
    } value;

    value.word = 1;
    return value.byte;
}
