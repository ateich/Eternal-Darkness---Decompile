unsigned short fn_8010940C(void* state)
{
    if (state != 0) {
        return *(unsigned short*)((unsigned char*)state + 0xA4);
    }
    return 1;
}
