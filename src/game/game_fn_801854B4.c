typedef unsigned char u8;
typedef signed short s16;

void fn_801854B4(u8* self, u8 value, u8 step)
{
    int count;
    int level;
    int index;
    int i;

    index = self[0x92];
    count = self[1];
    if (index < count && index >= 0) {
        self[0x90] = step;
        level = value;
        for (i = 0; i < index; i++) {
            u8* entry = *(u8**)(self + 0x4C) + i * 0x38;
            entry[0x2B] = level;
            entry[0x2F] = level;
            level -= step;
            if ((s16)level < 0)
                level = 0;
        }
    }

    if (index >= 0) {
        for (i = index; i < count; i++) {
            u8* entry = *(u8**)(self + 0x4C) + i * 0x38;
            entry[0x2B] = 0;
            entry[0x2F] = 0;
        }
    }

    {
        u8* entry = *(u8**)(self + 0x4C);
        entry[0x2B] = value;
        entry[0x2F] = value;
    }
}
