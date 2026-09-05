typedef unsigned char u8;
typedef unsigned short u16;

extern u8 lbl_8062A230[];

u16 fn_801CAFAC(int control, int channel, int layer)
{
    u8* base = lbl_8062A230;
    u8 channel8 = channel;

    if (channel8 != 0xFF) {
        u8 layer8 = layer;

        if (layer8 != 0xFF) {
            u8 control8 = control;

            if (control8 < 0x40) {
                u8* data = base + layer8 * 2144 + channel8 * 134 + (control8 & 0x1F);
                return (data[0xC0] << 7) | data[0xE0];
            }
            if (control8 < 0x46) {
                u8 value = base[layer8 * 2144 + channel8 * 134 + control8 + 0xC0];
                return value < 0x40 ? 0 : 0x3FFF;
            }
            if (control8 >= 0x60 && control8 < 0x66) {
                return 0;
            }
            if ((u8)(control - 0x80) <= 1) {
                u8* data = base + (u8)layer * 2144 + (u8)channel * 134 + ((u8)control & 0xFE);
                return (data[0xC0] << 7) | data[0xC1];
            }
            if ((u8)(control - 0x84) <= 1) {
                u8* data = base + (u8)layer * 2144 + (u8)channel * 134 + ((u8)control & 0xFE);
                return (data[0xC0] << 7) | data[0xC1];
            }
            return base[(u8)layer * 2144 + (u8)channel * 134 + (u8)control + 0xC0] << 7;
        }

        if ((u8)control < 0x40) {
            u8* data = base + channel8 * 134 + ((u8)control & 0x1F);
            return (data[0x43C0] << 7) | data[0x43E0];
        }
        if ((u8)control < 0x46) {
            u8 value = base[channel8 * 134 + (u8)control + 0x43C0];
            return value < 0x40 ? 0 : 0x3FFF;
        }
        if ((u8)control >= 0x60 && (u8)control < 0x66) {
            return 0;
        }
        if ((u8)(control - 0x80) <= 1) {
            u8* data = base + (u8)channel * 134 + ((u8)control & 0xFE);
            return (data[0x43C0] << 7) | data[0x43C1];
        }
        if ((u8)(control - 0x84) <= 1) {
            u8* data = base + (u8)channel * 134 + ((u8)control & 0xFE);
            return (data[0x43C0] << 7) | data[0x43C1];
        }
        return base[(u8)channel * 134 + (u8)control + 0x43C0] << 7;
    }
    return 0;
}
