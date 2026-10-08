extern unsigned char lbl_80325DB8[10][16];

int fn_800E783C(void)
{
    int i;
    int result = 1;

    for (i = 0; i < 10; i++) {
        if (*(int *)lbl_80325DB8[i] != 0) {
            result = 0;
            break;
        }
    }
    return result;
}
