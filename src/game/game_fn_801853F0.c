typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void* memcpy(void*, const void*, u32);
extern void fn_801806D4(void*, void*, int);

void fn_801853F0(u8* self, const void* value, u8 amount)
{
    int step;
    int count;
    int remaining;
    int index;
    u8* entry;
    u8 local[4];

    entry = *(u8**)(self + 0x4C);
    count = self[1];
    memcpy(local, value, 4);
    remaining = local[3];
    step = amount;
    index = 0;
    self[0x90] = amount;
    while (index < count) {
        fn_801806D4(entry + 0x20, local, 0);
        fn_801806D4(entry + 0x20, local, 1);
        remaining -= step;
        if ((signed short)remaining < 0)
            remaining = 0;
        local[3] = remaining;
        entry += 0x38;
        index++;
    }
    *(u16*)(self + 0xA4) |= 0x20;
}
