typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 lbl_8062A230[];
extern u8 lbl_80619C20[];
extern u8* lbl_8064D3D0;
extern void fn_801B7954(void*);

void fn_801CA7C0(u8 control, u8 channel, u8 layer, u8 value)
{
    u8* state_base = lbl_8062A230;
    if (channel == 0xFF) {
        return;
    }

    if (layer != 0xFF) {
        switch (control) {
        case 0x26:
            break;
        case 6:
            if ((u16)((state_base[layer * 2144 + channel * 134 + 293] << 8) |
                      state_base[layer * 2144 + channel * 134 + 292]) == 0) {
                u8 amount = value;
                u32 i;
                u32 offset;
                if (amount > 24) {
                    amount = 24;
                }
                state_base[layer * 16 + channel + 26432] = amount;
                for (i = 0, offset = i; i < lbl_80619C20[528]; offset += 1028, i++) {
                    u8* voice = lbl_8064D3D0 + offset;
                    if (layer == voice[290] && channel == voice[289]) {
                        voice[471] = amount;
                        lbl_8064D3D0[offset + 470] = amount;
                    }
                }
            }
            break;
        case 0x60:
            if ((u16)((state_base[layer * 2144 + channel * 134 + 293] << 8) |
                      state_base[layer * 2144 + channel * 134 + 292]) == 0) {
                u8 amount = state_base[layer * 16 + channel + 26432];
                u32 i;
                u32 offset;
                if (amount != 0) {
                    amount--;
                }
                state_base[layer * 16 + channel + 26432] = amount;
                for (i = 0, offset = i; i < lbl_80619C20[528]; offset += 1028, i++) {
                    u8* voice = lbl_8064D3D0 + offset;
                    if (layer == voice[290] && channel == voice[289]) {
                        voice[471] = amount;
                        lbl_8064D3D0[offset + 470] = amount;
                    }
                }
            }
            break;
        case 0x61:
            if ((u16)((state_base[layer * 2144 + channel * 134 + 293] << 8) |
                      state_base[layer * 2144 + channel * 134 + 292]) == 0) {
                u8 amount = state_base[layer * 16 + channel + 26432];
                u32 i;
                u32 offset;
                if (amount < 24) {
                    amount++;
                }
                state_base[layer * 16 + channel + 26432] = amount;
                for (i = 0, offset = i; i < lbl_80619C20[528]; offset += 1028, i++) {
                    u8* voice = lbl_8064D3D0 + offset;
                    if (layer == voice[290] && channel == voice[289]) {
                        voice[471] = amount;
                        lbl_8064D3D0[offset + 470] = amount;
                    }
                }
            }
            break;
        }

        state_base[layer * 2144 + channel * 134 + control + 192] = value & 0x7F;
        {
            u32 i;
            u32 offset;
            for (i = 0, offset = i; i < lbl_80619C20[528]; offset += 1028, i++) {
                u8* voice = lbl_8064D3D0 + offset;
                if (layer == voice[290] && channel == voice[289]) {
                    *(u32*)(voice + 532) = 8191;
                    fn_801B7954(voice);
                }
            }
        }
        *(u32*)(state_base + layer * 64 + channel * 4 + 25920) = 0xFF;
    } else {
        switch (control) {
        case 0x26:
            break;
        case 6:
            if ((u16)((state_base[layer * 2144 + channel * 134 + 293] << 8) |
                      state_base[layer * 2144 + channel * 134 + 292]) == 0) {
                u8 amount = value;
                u32 i;
                u32 offset;
                if (amount > 24) {
                    amount = 24;
                }
                state_base[layer * 16 + channel + 26432] = amount;
                for (i = 0, offset = i; i < lbl_80619C20[528]; offset += 1028, i++) {
                    u8* voice = lbl_8064D3D0 + offset;
                    if (layer == voice[290] && channel == voice[289]) {
                        voice[471] = amount;
                        lbl_8064D3D0[offset + 470] = amount;
                    }
                }
            }
            break;
        case 0x60:
            if ((u16)((state_base[layer * 2144 + channel * 134 + 293] << 8) |
                      state_base[layer * 2144 + channel * 134 + 292]) == 0) {
                u8 amount = state_base[layer * 16 + channel + 26432];
                u32 i;
                u32 offset;
                if (amount != 0) amount--;
                state_base[layer * 16 + channel + 26432] = amount;
                for (i = 0, offset = i; i < lbl_80619C20[528]; offset += 1028, i++) {
                    u8* voice = lbl_8064D3D0 + offset;
                    if (layer == voice[290] && channel == voice[289]) {
                        voice[471] = amount;
                        lbl_8064D3D0[offset + 470] = amount;
                    }
                }
            }
            break;
        case 0x61:
            if ((u16)((state_base[layer * 2144 + channel * 134 + 293] << 8) |
                      state_base[layer * 2144 + channel * 134 + 292]) == 0) {
                u8 amount = state_base[layer * 16 + channel + 26432];
                u32 i;
                u32 offset;
                if (amount < 24) amount++;
                state_base[layer * 16 + channel + 26432] = amount;
                for (i = 0, offset = i; i < lbl_80619C20[528]; offset += 1028, i++) {
                    u8* voice = lbl_8064D3D0 + offset;
                    if (layer == voice[290] && channel == voice[289]) {
                        voice[471] = amount;
                        lbl_8064D3D0[offset + 470] = amount;
                    }
                }
            }
            break;
        }

        state_base[channel * 134 + control + 17344] = value & 0x7F;
        {
            u32 i;
            u32 offset;
            for (i = 0, offset = i; i < lbl_80619C20[528]; offset += 1028, i++) {
                u8* voice = lbl_8064D3D0 + offset;
                if (layer == voice[290] && channel == voice[289]) {
                    *(u32*)(voice + 532) = 8191;
                    fn_801B7954(voice);
                }
            }
        }
    }
}
