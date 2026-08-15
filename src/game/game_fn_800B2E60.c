extern int fn_800B193C(void);
extern int fn_800B194C(void);

int fn_800B2E60(void)
{
    int result;

    if (fn_800B193C() != 0) {
        switch (fn_800B194C()) {
        case 0:
        case 1:
        case 3:
            result = 1;
            break;
        default:
            result = 0;
            break;
        }
    } else {
        result = 1;
    }
    return result;
}
