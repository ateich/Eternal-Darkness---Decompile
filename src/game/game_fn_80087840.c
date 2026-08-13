typedef unsigned short u16;

typedef struct Setting {
    float first;
    float second;
    u16 pad8;
    u16 padA;
    u16 third;
    u16 fourth;
    u16 cleared;
    u16 fifth;
} Setting;

extern unsigned char lbl_8031CBA0[];
extern int lbl_8064D18C;

void fn_80087840(u16 fourth, float first, u16 third, float second, u16 fifth)
{
    Setting* setting;

    switch (lbl_8064D18C) {
    case 313:
        setting = (Setting*)(lbl_8031CBA0 + 0x128);
        break;
    case 233:
        setting = (Setting*)(lbl_8031CBA0 + 0x13C);
        break;
    case 168:
        setting = (Setting*)(lbl_8031CBA0 + 0x150);
        break;
    case 306:
        setting = (Setting*)(lbl_8031CBA0 + 0x164);
        break;
    case 308:
        setting = (Setting*)(lbl_8031CBA0 + 0x178);
        break;
    default:
        return;
    }

    setting->fourth = fourth;
    setting->first = first;
    setting->second = second;
    setting->cleared = 0;
    setting->third = third;
    setting->fifth = fifth;
}
