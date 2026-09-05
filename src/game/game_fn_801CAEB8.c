typedef unsigned char u8;
typedef unsigned int u32;

extern u8 lbl_8023B348[];
extern u8 lbl_8023B3D0[];
extern u8 lbl_8062A2F0[];
extern u8 lbl_8062E5F0[];
extern void* memcpy(void*, const void*, u32);
extern void fn_801CB470(int, int, int);

void fn_801CAEB8(int channel, u32 layer, u32 copy_all)
{
    u8* source = copy_all != 0 ? lbl_8023B348 : lbl_8023B3D0;
    u8* destination;

    if ((u8)layer != 0xFF) {
        destination = lbl_8062A2F0 + (u8)layer * 2144 + (u8)channel * 134;
    } else {
        destination = lbl_8062E5F0 + (u8)channel * 134;
    }

    if (copy_all != 0) {
        memcpy(destination, source, 134);
    } else {
        u32 i;
        for (i = 0; i < 134; i++) {
            if (source[i] != 0xFF) {
                destination[i] = source[i];
            }
        }
    }

    fn_801CB470(channel, layer, 0xFF);
}
