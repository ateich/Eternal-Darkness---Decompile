typedef unsigned char u8;

extern u8 lbl_8062A230[];
extern u8 lbl_8062A2B0[];

void fn_801CB470(int index, int layer, u8 value)
{
    u8* destination;

    if ((u8)layer != 0xFF) {
        destination = lbl_8062A230 + (u8)layer * 16 + (u8)index;
        *destination = value;
        return;
    }
    destination = lbl_8062A2B0 + (u8)index;
    *destination = value;
}
