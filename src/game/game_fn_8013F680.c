typedef struct ValueAt8 {
    unsigned char pad[8];
    float value;
} ValueAt8;

extern double lbl_806503B8, lbl_806503C0, lbl_806503C8, lbl_806503D0;

int fn_8013F680(const ValueAt8* value)
{
    if (value->value >= lbl_806503B8 && value->value <= lbl_806503C0)
        return 3;
    if (value->value >= lbl_806503C8 && value->value <= lbl_806503D0)
        return 2;
    return 1;
}
