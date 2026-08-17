extern int lbl_8064D080;
extern unsigned char lbl_805B4400[];

void* fn_80149360(void)
{
    int index = lbl_8064D080;
    void* result = 0;

    if (index < 8) {
        result = lbl_805B4400 + index * 0xC4;
        lbl_8064D080 = index + 1 < 8 ? index + 1 : 8;
    }
    return result;
}
