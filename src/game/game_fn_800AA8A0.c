extern void* lbl_8064D18C;
extern int fn_8006D548(int, int, int, void*, int, void*, int);
extern int fn_800CB254(int, int, void*, void*, int);

int fn_800AA8A0(void* object, void* other)
{
    int selector = 7;
    int result = 0;
    int count = 0;

    do {
        if (fn_8006D548(2, 8, selector, object, 0, other, 0) >= 0) {
            if (fn_800CB254(0, 200, object, lbl_8064D18C, 0) != 0) {
                selector = 2;
            } else {
                result = 1;
            }
        }
        count++;
        if (count > 10 && result == 0) {
            break;
        }
    } while (result == 0);

    return result;
}
