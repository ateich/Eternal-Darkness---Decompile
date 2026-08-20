typedef unsigned short u16;

void fn_8016D9C0(unsigned int type, u16* first, u16* second)
{
    switch (type) {
    case 0:
        *first = 0;
        *second = 1;
        break;
    case 1:
        *first = 0;
        *second = 2;
        break;
    case 2:
        *first = 0;
        *second = 4;
        break;
    case 3:
        *first = 2;
        *second = 5;
        break;
    case 4:
        *first = 0;
        *second = 8;
        break;
    case 5:
        *first = 2;
        *second = 0;
        break;
    case 6:
        *first = 0;
        *second = 0x20;
        break;
    case 7:
        *first = 0x3f;
        *second = 0;
        break;
    }
}
