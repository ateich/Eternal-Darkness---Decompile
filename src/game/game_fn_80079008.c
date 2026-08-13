extern int fn_80128EAC(void *object);

int fn_80079008(void *unused, void *object)
{
    int result = 1;
    int kind = fn_80128EAC(object);

    switch (kind) {
    case 0x76:
    case 0x77:
    case 0x78:
    case 0x79:
    case 0x7A:
    case 0x7B:
    case 0x7C:
        result = 0;
        break;
    }
    return result;
}
