typedef unsigned char u8;

int fn_8018D1F0(u8 level, int value)
{
    int result;

    if (level >= 1) {
        if (value > 2400) {
            int divisor = level - 1;
            if (level == 1) {
                divisor = 1;
            }
            result = (int)((float)(8001 - value) / (5601.0f / (float)divisor)) + 1;
        } else {
            result = level + (int)((float)(2401 - value) / (800.0f / (float)level));
        }
        if (result < level) {
            result = level;
        }
    } else {
        result = 0;
    }
    return result;
}
