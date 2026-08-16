extern int fn_80128EAC(void *);

int fn_800D0454(void *unused, void *object)
{
    int result = 1;

    switch (fn_80128EAC(object)) {
    case 78:
    case 111:
        result = 0;
        break;
    }

    return result;
}
