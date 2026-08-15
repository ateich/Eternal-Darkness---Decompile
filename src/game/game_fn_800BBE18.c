int fn_800BBE18(unsigned char *state)
{
    unsigned int i;
    long long best = -1;
    int result = 0;

    for (i = 0; i < 6; i++) {
        unsigned char *entry = state + state[0x1B0 + i] * 0x38;
        if (*(int *)(entry + 0x28) == 1 && *(long long *)(entry + 0x48) > best) {
            best = *(long long *)(entry + 0x48);
            result = i;
        }
    }
    return result;
}
