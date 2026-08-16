extern int fn_8011EB04(void *);

int fn_800CC2D8(void *object, int group)
{
    int result = 0;
    int kind;

    if (group != 0) {
        kind = fn_8011EB04(object);
        switch (kind) {
        case 0x5F:
        case 0x60:
        case 0x7D:
            result = 1;
            break;
        }
    } else {
        kind = fn_8011EB04(object);
        switch (kind) {
        case 0x30:
        case 0x5C:
        case 0x5F:
        case 0x60:
        case 0x61:
        case 0x74:
        case 0x76:
        case 0x78:
        case 0x7B:
        case 0x7C:
        case 0x7D:
        case 0x7E:
        case 0xC1:
        case 0xC6:
            result = 1;
            break;
        }
    }
    return result;
}
