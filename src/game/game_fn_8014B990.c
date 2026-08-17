typedef unsigned char u8;

extern void* lbl_805B4A20[6];
extern void* lbl_805B4A38[6];
extern u8 lbl_8064D0A8;

extern void fn_801964E8(void*, int, int);
extern void fn_80142FCC(void*);

void fn_8014B990(int index, int mode)
{
    void* object = lbl_805B4A20[index];

    if (object != 0) {
        fn_801964E8(object, 0, mode);
        lbl_805B4A20[index] = 0;
    }

    object = lbl_805B4A38[index];
    if (object != 0) {
        fn_80142FCC(object);
        lbl_805B4A38[index] = 0;
    }
    lbl_8064D0A8--;
}
