typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern float lbl_8064F504;
extern float lbl_8064F508;
extern float lbl_8064F50C;
extern float lbl_8064F510;
extern float lbl_8064F514;
extern float lbl_8064F518;
extern float lbl_8064F51C;
extern float lbl_8064F520;
extern float lbl_8064F524;
extern float lbl_8064F528;
extern float lbl_8064F52C;
extern float lbl_8064F530;
extern float lbl_8064F534;
extern float lbl_8064F538;
extern float lbl_8064F53C;
extern float lbl_8064F540;
extern float lbl_8064F544;
extern float lbl_8064F548;
extern float lbl_8064F54C;
extern float lbl_8064F550;
extern float lbl_8064F554;
extern float lbl_8064F558;

int fn_800DE8FC(int type, Vec3 *position)
{
    float x;
    float y;
    int result = 1;

    switch (type) {
    case 0xED:
        y = lbl_8064F508;
        x = lbl_8064F504;
        position->x = x;
        x = lbl_8064F50C;
        position->y = y;
        position->z = x;
        break;
    case 0xEE:
        y = lbl_8064F514;
        x = lbl_8064F510;
        position->x = x;
        x = lbl_8064F518;
        position->y = y;
        position->z = x;
        break;
    case 0xF5:
        y = lbl_8064F520;
        x = lbl_8064F51C;
        position->x = x;
        x = lbl_8064F524;
        position->y = y;
        position->z = x;
        break;
    case 0xF6:
        y = lbl_8064F52C;
        x = lbl_8064F528;
        position->x = x;
        x = lbl_8064F530;
        position->y = y;
        position->z = x;
        break;
    case 0xF4:
        y = lbl_8064F538;
        x = lbl_8064F534;
        position->x = x;
        x = lbl_8064F50C;
        position->y = y;
        position->z = x;
        break;
    case 0xF2:
        y = lbl_8064F540;
        x = lbl_8064F53C;
        position->x = x;
        x = lbl_8064F530;
        position->y = y;
        position->z = x;
        break;
    case 0xF1:
        y = lbl_8064F548;
        x = lbl_8064F544;
        position->x = x;
        x = lbl_8064F50C;
        position->y = y;
        position->z = x;
        break;
    case 0xF7:
        y = lbl_8064F550;
        x = lbl_8064F54C;
        position->x = x;
        x = lbl_8064F50C;
        position->y = y;
        position->z = x;
        break;
    case 0xF8:
        y = lbl_8064F558;
        x = lbl_8064F554;
        position->x = x;
        x = lbl_8064F530;
        position->y = y;
        position->z = x;
        break;
    case 0xEF:
    case 0xF0:
    case 0xF3:
    default:
        result = 0;
        break;
    }

    return result;
}
