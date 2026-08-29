typedef unsigned char u8;

void fn_8019453C(u8* value, int amount, const u8* minimum)
{
    u8 floor;
    u8 amount8;

    floor = minimum[0];
    amount8 = amount;
    if (value[0] > amount8 + floor) {
        value[0] -= amount;
    } else {
        value[0] = floor;
    }
    floor = minimum[1];
    if (value[1] > amount8 + floor) {
        value[1] -= amount;
    } else {
        value[1] = floor;
    }
    floor = minimum[2];
    if (value[2] > amount8 + floor) {
        value[2] -= amount;
    } else {
        value[2] = floor;
    }
    floor = minimum[3];
    if (value[3] > amount8 + floor) {
        value[3] -= amount;
    } else {
        value[3] = floor;
    }
}
