extern unsigned int lbl_8064CE8C;

void fn_8011E19C(unsigned int mask, int enabled)
{
    unsigned int value = lbl_8064CE8C & ~mask;

    if (enabled != 0) {
        value = lbl_8064CE8C | mask;
    }
    lbl_8064CE8C = value;
}
