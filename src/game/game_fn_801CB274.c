typedef unsigned char u8;

extern u8 lbl_80630970[];
extern u8 lbl_806309F0[];

void fn_801CB274(int index, int layer)
{
    u8* value;

    if ((u8)layer != 0xFF) {
        value = lbl_80630970 + (u8)layer * 16 + (u8)index;
    } else {
        value = lbl_806309F0 + (u8)index;
    }
    *value = 2;
}
