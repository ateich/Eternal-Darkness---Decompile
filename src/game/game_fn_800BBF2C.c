unsigned char fn_800BBF2C(unsigned char *state)
{
    unsigned char i;

    for (i = 0; i < 7; i++) {
        if (*(int *)(state + i * 0x38 + 0x28) == 2)
            return i;
    }
    return 0;
}
