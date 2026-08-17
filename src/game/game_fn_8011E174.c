extern unsigned int lbl_8064CE88;

void fn_8011E174(unsigned int mask, int enabled)
{
    unsigned int value = lbl_8064CE88 & ~mask;

    if (enabled != 0) {
        value = lbl_8064CE88 | mask;
    }
    lbl_8064CE88 = value;
}
