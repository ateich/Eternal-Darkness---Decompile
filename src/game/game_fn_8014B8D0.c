extern void* lbl_805B4A20[6];
extern void* lbl_805B4A38[6];

int fn_8014B8D0(void* first, void* second)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (lbl_805B4A20[i] == 0) {
            lbl_805B4A20[i] = first;
            lbl_805B4A38[i] = second;
            return i;
        }
    }
    return 0;
}
