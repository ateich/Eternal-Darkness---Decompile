typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_8018163C(void*, void*, u8, u16);

void fn_801865EC(u8* self, void* setup, int index)
{
    u8* entry = *(u8**)(self + 0x4C) + index * 0x38;
    u16 count = *(u16*)(self + 0x9A);
    u8 phase;

    if (index < self[1] - 1) {
        phase = (int)(index * *(float*)(self + 0xBC)) & 0x3F;
    } else {
        phase = 0;
    }
    fn_8018163C(entry, setup, phase, count);
}
