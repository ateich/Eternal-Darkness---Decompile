typedef unsigned char u8;

u8 fn_8019F1EC(u8* state, u8* value)
{
    if (*value == state[1])
        state[0] = 0;
    if (state[0] != 0)
        *value += state[2];
    return state[0];
}
