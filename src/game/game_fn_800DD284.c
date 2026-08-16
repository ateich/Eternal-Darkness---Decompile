extern int lbl_8064D18C;
extern int lbl_8064C578;

int fn_800DD284(void)
{
    int result = -1;

    switch (lbl_8064D18C) {
    case 245:
        if (lbl_8064C578 >= 1) {
            result = 15;
        } else {
            result = 14;
        }
        break;
    case 238:
        result = 14;
        break;
    case 237:
        result = 3;
        break;
    case 246:
        result = 23;
        break;
    case 244:
        result = 9;
        break;
    case 243:
        result = 10;
        break;
    case 241:
        result = 4;
        break;
    case 242:
        result = 3;
        break;
    case 247:
        result = 5;
        break;
    case 239:
    case 240:
        break;
    case 248:
        result = 2;
        break;
    }

    return result;
}
