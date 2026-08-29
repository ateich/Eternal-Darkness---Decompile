typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void fn_801E7DC8(int value);
void fn_80195AEC(u8* object);

int fn_80195960(u8* object)
{
    u8 phase;
    u8 count = object[0x97];

    if (count <= 0x11 && count >= 5) {
        phase = object[0x95];

        if (phase == 0) {
            u8 current;
            u32 flags = *(volatile u32*)(object + 0x108);
            if ((flags & 0x40000) ||
                ((flags & 0x10) &&
                 (object[0x96] >= count || !(flags & 0x20)))) {
                current = object[0x8E];
                if (current == count) {
                    if (!(flags & 0x200)) {
                        *(u16*)(object + 0x22) = 8;
                        fn_801E7DC8(0x104);
                        fn_801E7DC8(0x100);
                    } else {
                        u32 value = *(volatile u32*)(object + 0x108);
                        value &= ~0x40000;
                        *(u32*)(object + 0x108) = value;
                        object[0x8E] = 0;
                        object[0x96] = 0;
                        *(u32*)(object + 0x148) = 0;
                    }
                } else if (*(u32*)(object + 0x148) != 0) {
                    object[0x8E] = current + 1;
                }
            }

            if (*(u32*)(object + 0x148) != 0) {
                if (!(*(u32*)(object + 0x108) & 0x40))
                    fn_80195AEC(object);
                if (object[0x96] < object[0x97])
                    object[0x96]++;
            }
            flags = *(u32*)(object + 0x108);
            if (!(flags & 1) && !(flags & 2) && !(flags & 4))
                object[0x95] = object[0x94];
        } else {
            u32 flags = *(u32*)(object + 0x108);
            if (!(flags & 1) && !(flags & 2) && !(flags & 4))
                object[0x95] = phase - 1;
        }

        {
        u32 endFlags;
        (*(u16*)(object + 0xA))++;
        endFlags = *(u32*)(object + 0x108);
        if (!(endFlags & 8) &&
            *(u16*)(object + 0xA) == *(u16*)(object + 0xC)) {
            *(u32*)(object + 0x108) = endFlags | 0x40000;
        }
        }
    }
    return 1;
}
