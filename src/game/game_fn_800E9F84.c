extern void *lbl_80325F1C[6];

void fn_800E9F84(void *value)
{
    int i;
    int done;

    done = 0;
    i = 0;

    while (i < 6 && done == 0) {
        if (value == lbl_80325F1C[i]) {
            done = 1;
            lbl_80325F1C[i] = 0;
        }
        i++;
    }
}
