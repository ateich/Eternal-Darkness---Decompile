typedef unsigned char u8;

extern u8 lbl_8062A230[];
extern u8 lbl_8062A2B0[];

u8 fn_801CB4B4(int index, int layer)
{
    u8* source;

    if ((u8)layer != 0xFF) {
        source = lbl_8062A230 + (u8)layer * 16 + (u8)index;
        return *source;
    }
    source = lbl_8062A2B0 + (u8)index;
    return *source;
}
