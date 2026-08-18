int fn_80152360(int kind, int value)
{
    int result = value;

    switch (kind) {
    case 0x124:
        if (value == 0x8C)
            result = 0x0C;
        if (value < 0x0C)
            result = 0x0C;
        break;
    case 0x117:
        if (value >= 0xE5 && value <= 0xEB) {
            result = 0x95;
        } else {
            switch (value) {
            case 0xA5:
            case 0xA6:
            case 0xB3:
            case 0xB4:
            case 0xB6:
            case 0xB7:
            case 0xD3:
            case 0xD4:
            case 0xD5:
            case 0xD6:
            case 0xD7:
            case 0xD8:
                result = 0x95;
            }
        }
        break;
    }
    return result;
}
