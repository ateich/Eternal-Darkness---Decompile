extern int fn_80128EAC(void *);

int fn_800D6314(void *unused, void *object)
{
    int result = 1;
    switch (fn_80128EAC(object)) {
    case 0x90:
        result = 0;
        break;
    }
    return result;
}
