extern volatile unsigned int lbl_8032A578;
extern unsigned char lbl_8032B694[];

int fn_800F564C(unsigned char value)
{
    unsigned int index = lbl_8032A578;
    lbl_8032B694[index] = value;
    lbl_8032A578 = index + 1;
    return 0;
}
