extern void* lbl_805B4A20[6];
extern void* lbl_805B4A38[6];

void fn_8014B888(int index, void** first, void** second)
{
    if (index >= 0 && index < 6) {
        *first = lbl_805B4A20[index];
        *second = lbl_805B4A38[index];
    } else {
        *first = 0;
        *second = 0;
    }
}
