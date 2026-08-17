extern char lbl_802FC5BC[];
extern int lbl_8065022C;
extern int lbl_80650230;
extern int lbl_80650234;
extern int lbl_8064B800;
extern int lbl_8064CBB8;

void fn_80131A28(int value)
{
    int state;
    int zero;
    int one;

    if (value == 0xAE) {
        state = lbl_8065022C;
        zero = 0;
        one = 1;
        lbl_8064B800 = zero;
        lbl_8064CBB8 = one;
        *(int*)(lbl_802FC5BC + 0x38) = state;
        return;
    }
    if (value == 0x150 || value == 0x18) {
        state = lbl_80650230;
        zero = 0;
        one = 1;
        lbl_8064B800 = zero;
        lbl_8064CBB8 = one;
        *(int*)(lbl_802FC5BC + 0x38) = state;
        return;
    }
    state = lbl_80650234;
    one = 1;
    lbl_8064B800 = one;
    lbl_8064CBB8 = one;
    *(int*)(lbl_802FC5BC + 0x38) = state;
}
