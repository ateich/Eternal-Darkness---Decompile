extern int fn_8011EB04(void*);

int fn_80092BBC(void* unused, void* object)
{
    int result = 0;

    switch (fn_8011EB04(object)) {
    case 103:
    case 105:
    case 106:
    case 107:
    case 108:
    case 109:
    case 117:
    case 133:
        result = 1;
        break;
    }
    return result;
}
