typedef int s32;

s32 fn_8002EA18(s32 value)
{
    s32 result = 0;
    s32 type = value & 0x70000;

    switch (type) {
    case 0x10000:
        result = 70;
        break;
    case 0x20000:
        result = 85;
        break;
    case 0x40000:
        result = 100;
        break;
    }
    return result;
}
