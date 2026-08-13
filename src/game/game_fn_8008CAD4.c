typedef unsigned short u16;

extern float lbl_8064EBF8;
extern float lbl_8064EBFC;
extern float lbl_8064EC00;
extern int fn_8006749C(int);
extern void fn_80120AD0(void*, int, int, u16, float, float);

void fn_8008CAD4(int unused, void* object, int kind, int type)
{
    float duration = lbl_8064EBF8;
    u16 base_flags = (u16)fn_8006749C(kind);
    u16 flags;
    int amount;

    flags = base_flags | 2;

    switch (type) {
    default:
    case 0:
        duration = lbl_8064EBFC;
        amount = 16;
        break;
    case 1:
        flags |= 0x200;
        amount = 320;
        break;
    case 2:
        flags |= 0x200;
        amount = 160;
        break;
    case 3:
        flags |= 0x200;
        amount = 80;
        break;
    }

    fn_80120AD0(object, 0, amount, flags, lbl_8064EC00, duration);
}
