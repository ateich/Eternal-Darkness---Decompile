typedef unsigned char u8;

void fn_80186A58(u8* self, int enabled)
{
    if (enabled != 0) {
        self[0x91] |= 1;
    } else {
        self[0x91] &= ~1;
    }
}
