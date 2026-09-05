typedef unsigned char u8;

extern u8 lbl_80630970[];
extern u8 lbl_806309F0[];

u8* fn_801CB238(int index, int layer)
{
    if ((u8)layer == 0xFF) {
        return lbl_806309F0 + (u8)index;
    }
    return lbl_80630970 + (u8)layer * 16 + (u8)index;
}
