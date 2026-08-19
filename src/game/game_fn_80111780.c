extern unsigned int* lbl_8064C4E0;
extern unsigned int lbl_80331748[];
extern int fn_801118E8(void);
extern int fn_80111BB0(void);
extern int fn_801E79FC(void*, int);

int fn_80111780(void)
{
    int index = fn_80111BB0();

    if (fn_801118E8() != 0) {
      if (index >= 0) {
          return 1;
      }
      if (fn_801E79FC(lbl_8064C4E0, 0x1F3) != 0 &&
        fn_801E79FC(lbl_8064C4E0, 0x1F4) == 0) {
        return 1;
      }
      if (fn_801E79FC(lbl_8064C4E0, 0x3D) != 0 &&
        fn_801E79FC(lbl_8064C4E0, 0x3C) == 0) {
        return 1;
      }
      if (fn_801E79FC(lbl_8064C4E0, 0x3DD) != 0 &&
        fn_801E79FC(lbl_8064C4E0, 0x3DE) == 0) {
        return 1;
      }
      if (fn_801E79FC(lbl_8064C4E0, 0x3DF) != 0 &&
        fn_801E79FC(lbl_8064C4E0, 0x3E0) == 0) {
        return 1;
      }
      if ((lbl_80331748[1] & 0x20000) != 0 &&
        fn_801E79FC(lbl_8064C4E0, 0xA9) == 0) {
        return 1;
      }
      if ((lbl_80331748[0] & 0x20000000) != 0 &&
        fn_801E79FC(lbl_8064C4E0, 0xAA) == 0) {
        return 1;
      }
    }
    return 0;
}
