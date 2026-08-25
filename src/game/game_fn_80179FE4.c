extern float lbl_80650860;
extern float lbl_8065086C;

float fn_80179FE4(const float* values, int raw, float amount)
{
    if (values[2] < lbl_80650860) {
        amount = amount;
    } else {
        amount = -amount;
    }

    if (!raw) {
        return amount;
    }

    return lbl_8065086C + amount;
}
