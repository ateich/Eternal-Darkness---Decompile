typedef unsigned char u8;

float lbl_80248910[3] = { 0.0f, 0.0f, 1.0f };

int fn_800CA13C(u8 kind)
{
    switch (kind) {
    case 41:
        return 30;
    case 39:
        return 80;
    case 3:
        return 80;
    case 8:
        return 50;
    case 4:
        return 220;
    case 5:
        return 60;
    case 6:
        return 40;
    case 7:
        return 100;
    case 12:
        return 100;
    case 37:
        return 80;
    default:
        return -1;
    }
}
