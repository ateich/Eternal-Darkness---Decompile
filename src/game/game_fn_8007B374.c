extern char lbl_802FC5BC[];
extern const float lbl_8064E984;
extern const float lbl_8064E988;
extern const float lbl_8064E98C;

extern void fn_800CEB10(int type, int variant, void *object, int zero,
                       int first, int second, float x, float y, float z,
                       void *data);

void fn_8007B374(void *object)
{
    fn_800CEB10(0x17, 2, object, 0, 4, 5, lbl_8064E984,
                lbl_8064E988, lbl_8064E98C, lbl_802FC5BC + 4);
}
